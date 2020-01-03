#include "Competicao.h"

Competicao::Competicao(string nome, Equipe** equipes, int quantidade) : nome(nome), equipes(equipes),
                        quantidade(quantidade)
{
    if (quantidade < 2)
        throw new invalid_argument ("Quantidade de equipes insuficiente");
}

Competicao::~Competicao()
{}

string Competicao::getNome(){
    return nome;
}

int Competicao::getQuantidadeDeEquipes(){
    return quantidade;
}

Equipe** Competicao::getEquipes(){
    return equipes;
}

/*
Tabela* Competicao::getTabela(){

}
*/

/*
void Competicao::imprimir(){
    cout << nome << endl;
    cout <<
}
*/
