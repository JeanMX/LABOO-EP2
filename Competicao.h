#ifndef COMPETICAO_H
#define COMPETICAO_H
#include <stdexcept>

#include <iostream>
#include <string>
#include "Equipe.h"
#include "Tabela.h"

using namespace std;
class Competicao
{
    public:
        Competicao(string nome, Equipe** equipes, int quantidade);
        virtual ~Competicao();
        string getNome();
        Equipe** getEquipes();
        int getQuantidadeDeEquipes();
        virtual Tabela* getTabela() = 0;
        virtual void imprimir() = 0;

    protected:
        string nome;
        Equipe** equipes;
        int quantidade;

};

#endif // COMPETICAO_H
