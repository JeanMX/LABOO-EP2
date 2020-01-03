#include "CompeticaoSimples.h"


CompeticaoSimples::CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m) : Competicao(nome, equipes, quantidade)
{
this->m = m;
}

CompeticaoSimples::~CompeticaoSimples()
{}

Modalidade* CompeticaoSimples::getModalidade(){
    return m;
}

Tabela* CompeticaoSimples::getTabela(){
    return m->getTabela();
    //PROVAVELMENTE VAI PRECISAR DE UM CAST AQUI

}

void CompeticaoSimples::imprimir(){
    cout << endl << nome << endl;
    m->imprimir() ;
}
