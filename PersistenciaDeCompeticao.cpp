#include "PersistenciaDeCompeticao.h"

PersistenciaDeCompeticao::PersistenciaDeCompeticao()
{}

PersistenciaDeCompeticao::~PersistenciaDeCompeticao()
{}

Competicao* PersistenciaDeCompeticao::carregar(string arquivo){
    ifstream input;
    input.open(arquivo);

    if(!input){
        throw new invalid_argument("Erro na leitura");
    }

    int quantidadeDeEquipes;
    input >> quantidadeDeEquipes;

    Equipe** equipes = new Equipe*[quantidadeDeEquipes];
    string nomeDaEquipe;

    for(int i = 0; i < quantidadeDeEquipes; i++){
        input >> nomeDaEquipe;
        equipes[i] = new Equipe(nomeDaEquipe);
        string nomeDaCompeticao;
    }

    string nomeDaCompeticao;
    input >> nomeDaCompeticao;

    bool tipoDeCompeticao;
    input >> tipoDeCompeticao;
    if(!input)
        throw new invalid_argument("Tipo de competicao invalido");

    bool temResultado;
    string nomeDaModalidade;
    string nomeDoParticipante;
    int quantidadeDeParticipantes;


    if(!tipoDeCompeticao){
        input >> nomeDaModalidade;
        Modalidade* modalidade = new Modalidade(nomeDaModalidade, equipes, quantidadeDeEquipes);

        input >> temResultado;
        if(!input)
            throw new invalid_argument("Erro no resultado");

        input >> quantidadeDeParticipantes;
        if(!input)
            throw new invalid_argument("Erro na quantidade de participantes");

        Equipe** participantes = new Equipe*[quantidadeDeParticipantes];

        for(int j = 0; j < quantidadeDeParticipantes; j++){
            input >> nomeDoParticipante;
            participantes[j] = new Equipe(nomeDoParticipante);
            }
        CompeticaoSimples* competicaoSimples = new CompeticaoSimples(nomeDaCompeticao, equipes, quantidadeDeParticipantes, modalidade);
        if(temResultado)
            competicaoSimples->getModalidade()->setResultado(participantes);
        return competicaoSimples;
        }
    else{ //CompeticaoMultiModalidade
        int quantidadeDeModalidade;
        CompeticaoMultimodalidades* competicaoMultimodalidades = new CompeticaoMultimodalidades(nomeDaCompeticao, equipes, quantidadeDeEquipes);
        input >> quantidadeDeModalidade;
        if(!input)
            throw new invalid_argument("Erro na quantidade de modalidades");

        Modalidade** modalidade = new Modalidade*[quantidadeDeModalidade];

        for(int i = 0; i < quantidadeDeModalidade; i++){
            input >> nomeDaModalidade;
            modalidade[i] = new Modalidade(nomeDaModalidade, equipes, quantidadeDeEquipes);

            input >> temResultado;
            if(!input)
                throw new invalid_argument("Erro para saber se tem resultado");
            input >> quantidadeDeParticipantes;
            if(!input)
                throw new invalid_argument("Erro na quantidade de participantes");
            Equipe** participantes = new Equipe*[quantidadeDeParticipantes];

            for(int k = 0; k < quantidadeDeParticipantes; k++){
                input >> nomeDoParticipante;
                participantes[k] = new Equipe(nomeDoParticipante);
             }
             if(temResultado){
                modalidade[i]->setResultado(participantes);
             }
             //delete[] participantes;
             competicaoMultimodalidades->adicionar(modalidade[i]);
           }
           return competicaoMultimodalidades;
        }
}

void PersistenciaDeCompeticao::salvar(string arquivo, Competicao* c){
    ofstream output;
    output.open(arquivo);

    if(!output){
        throw new invalid_argument("");
    }

    CompeticaoSimples* competicaoSimples = dynamic_cast<CompeticaoSimples*>(c);
    CompeticaoMultimodalidades* competicaoMultimodalidades = dynamic_cast<CompeticaoMultimodalidades*>(c);

    if(competicaoSimples == 0){
        int quantidadeDeEquipes = competicaoMultimodalidades->getQuantidadeDeEquipes();
        output << quantidadeDeEquipes << " ";
        for(int i = 0; i < quantidadeDeEquipes; i++){
            output << competicaoMultimodalidades->getEquipes()[i]->getNome() << " ";
        }
        output << endl << competicaoMultimodalidades->getNome()<< endl << "1" << endl <<competicaoMultimodalidades->getModalidades()->size();
        list<Modalidade*>::iterator i = competicaoMultimodalidades->getModalidades()->begin();
        while(i != competicaoMultimodalidades->getModalidades()->end()){
            output << endl << (*i)->getNome() << endl << (*i)->temResultado() << " " << competicaoMultimodalidades->getQuantidadeDeEquipes();
            for(int k = 0; k < competicaoMultimodalidades->getQuantidadeDeEquipes(); k++){
                if((*i)->temResultado()){
                    output << " " << (*i)->getTabela()->getEquipesEmOrdem()[k]->getNome();
                }
                else {
                    output << " " << (*i)->getEquipes()[k]->getNome();
                }
            }
            i++;
        }
    }
    else{
        int quantidadeDeEquipes = competicaoSimples->getQuantidadeDeEquipes();
        output << quantidadeDeEquipes << " ";
        for(int i = 0; i < quantidadeDeEquipes; i++){
            output << competicaoSimples->getModalidade()->getEquipes()[i]->getNome() << " ";
        }
        output << endl << competicaoSimples->getNome();
        output << endl << "0";
        output << endl << competicaoSimples->getModalidade()->getNome() << " ";
        output << endl << competicaoSimples->getModalidade()->temResultado();
        output << " " << quantidadeDeEquipes << endl;
        for(int j = 0; j < quantidadeDeEquipes; j++){
            if(competicaoSimples->getModalidade()->temResultado() == true)
                output << " " << competicaoSimples->getModalidade()->getTabela()->getEquipesEmOrdem()[j]->getNome();
            else
                output << " " << competicaoSimples->getModalidade()->getEquipes()[j]->getNome();
        }
    }
}
