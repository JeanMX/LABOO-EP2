#ifndef MODALIDADE_H
#define MODALIDADE_H

#include <iostream>
#include <string>
#include <stdexcept>

#include "Tabela.h"
#include "Equipe.h"
#include "TabelaComOrdem.h"

using namespace std;

class Modalidade
{
    public:
        Modalidade(string nome, Equipe** participantes, int quantidade);
        virtual ~Modalidade();

        virtual string getNome();
        virtual Equipe** getEquipes();
        virtual int getQuantidadeDeEquipes();
        virtual void setResultado(Equipe** ordem);
        virtual bool temResultado();
        virtual TabelaComOrdem* getTabela();
        virtual void imprimir();

    protected:
        string nome;
        Equipe** participantes;
        int quantidade;
        TabelaComOrdem* tabela;
        bool status = false;
};

#endif // MODALIDADE_H
