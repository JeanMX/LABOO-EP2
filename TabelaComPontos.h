#ifndef TABELACOMPONTOS_H
#define TABELACOMPONTOS_H

#include <iostream>

#include "Equipe.h"
#include "Tabela.h"

using namespace std;

class TabelaComPontos : public Tabela
{
    public:
        TabelaComPontos (Equipe** participantes, int quantidade);
        virtual ~TabelaComPontos();
        int getPontos (Equipe* participante);
        void pontuar (Equipe* participante, int pontos);
        int getPosicao(Equipe* participante);
        Equipe** getEquipesEmOrdem();
        void imprimir();

    protected:
        Equipe** participantes;
        int* pontos;
        int* pontosOrdenados;
        int quantidade;
        int posicao;
        int count = 0;
};

#endif // TABELACOMPONTOS_H
