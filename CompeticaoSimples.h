#ifndef COMPETICAOSIMPLES_H
#define COMPETICAOSIMPLES_H

#include <iostream>
#include <string>
#include <stdexcept>

#include "Equipe.h"
#include "Modalidade.h"
#include "Competicao.h"

using namespace std;

class CompeticaoSimples : public Competicao
{
    public:
        CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m);
        virtual ~CompeticaoSimples();
        Modalidade* getModalidade();
        virtual Tabela* getTabela();
        virtual void imprimir();

    protected:
        Modalidade* m;
};

#endif // COMPETICAOSIMPLES_H
