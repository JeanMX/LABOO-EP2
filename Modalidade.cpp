#include "Modalidade.h"

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade):
    nome(nome), participantes(participantes), quantidade(quantidade)
{
    tabela = new TabelaComOrdem(participantes, quantidade);
    if(quantidade < 2){
        throw new invalid_argument ("Quantidade insuficiente de equipes");
    }
}

Modalidade::~Modalidade()
{
   // tabela->~TabelaComOrdem();
}

string Modalidade::getNome(){
    return nome;
}

Equipe** Modalidade::getEquipes(){
    return participantes;
}

int Modalidade::getQuantidadeDeEquipes(){
    return quantidade;
}

void Modalidade::setResultado(Equipe** ordem){
        tabela->setResultado(ordem);
        status = true; //Verificar com o momnitor
}

bool Modalidade::temResultado(){
    if(status)
        return true;
    return false;
}

TabelaComOrdem* Modalidade::getTabela(){
        return tabela;
}

void Modalidade::imprimir(){
    //cout << "Modalidade: " << nome << endl;
    tabela->imprimir();
}
