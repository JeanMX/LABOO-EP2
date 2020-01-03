#ifndef TABELACOMORDEM_H
#define TABELACOMORDEM_H

#include <iostream>

#include "Tabela.h"
#include "Equipe.h"

using namespace std;

class TabelaComOrdem : public Tabela
{
    public:
        TabelaComOrdem (Equipe** participantes, int quantidade);
        virtual ~TabelaComOrdem();
        void setResultado (Equipe** ordem);
        int getPosicao(Equipe* participante);
        void imprimir();
        Equipe** getEquipesEmOrdem();

    protected:
        Equipe** participantes;
        int quantidade;
        bool resultado = false;
        Equipe** equipesOrdenadas;
};

#endif // TABELACOMORDEM_H
