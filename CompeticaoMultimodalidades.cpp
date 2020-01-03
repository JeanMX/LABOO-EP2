#include "CompeticaoMultimodalidades.h"

vector<int>* CompeticaoMultimodalidades::pontuacao = new vector<int>({13, 10, 8, 7, 5, 4, 3, 2, 1});

CompeticaoMultimodalidades::CompeticaoMultimodalidades(string nome, Equipe** equipes,
                int quantidade) : Competicao(nome, equipes, quantidade)
{
    this->nome = nome;
    this->quantidade = quantidade;
    tabela = new TabelaComPontos(equipes, quantidade);
}


CompeticaoMultimodalidades::~CompeticaoMultimodalidades()
{
    //delete[] pontuacao;
    //delete modalidades;
}

void CompeticaoMultimodalidades::adicionar(Modalidade* m){
    modalidades->push_back(m);
}

list<Modalidade*>* CompeticaoMultimodalidades::getModalidades(){
    return modalidades;
}

void CompeticaoMultimodalidades::setPontuacao(vector<int>* pontos){
    if(pontuacao->size() < 3 )
            throw new invalid_argument("Pontuacoes insuficientes");
    CompeticaoMultimodalidades::pontuacao = pontos;
}

int CompeticaoMultimodalidades::getPontoPorPosicao(int posicao){
    if(pontuacao->size() < posicao || posicao <= 0)
        return 0;
    return pontuacao->at(posicao - 1);
}

Tabela* CompeticaoMultimodalidades::getTabela(){
    if(modalidades->empty())
        throw new invalid_argument("Nenhuma modalidade adicionada");
    Equipe** equipesEmOrdem = new Equipe*[quantidade];
    list<Modalidade*>::iterator i = modalidades->begin();

    while(i != modalidades->end()){
        if((*i)->temResultado()){
            equipesEmOrdem = (*i)->getTabela()->getEquipesEmOrdem();
            for(int j = 0; j < quantidade; j++){
                    tabela->pontuar(equipesEmOrdem[j], pontuacao->at(j));
            }
        }
        i++;
    }
    return tabela;
}

void CompeticaoMultimodalidades::imprimir(){
    cout << endl << nome << endl;
    ->imprimir();
}
