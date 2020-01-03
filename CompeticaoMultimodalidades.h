#ifndef COMPETICAOMULTIMODALIDADES_H
#define COMPETICAOMULTIMODALIDADES_H

#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>

#include "Modalidade.h"
#include "Equipe.h"
#include "Competicao.h"
#include "TabelaComPontos.h"


using namespace std;

class CompeticaoMultimodalidades : public Competicao
{
    public:
        CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade);
        virtual ~CompeticaoMultimodalidades();
        void adicionar(Modalidade* m);
        list<Modalidade*>* getModalidades();
        static void setPontuacao(vector<int>* pontos);
        static int getPontoPorPosicao(int posicao);
        virtual Tabela* getTabela();
        virtual void imprimir();


    protected:
        list<Modalidade*>* modalidades = new list<Modalidade*>();
        static vector<int>* pontuacao;
        int quantidadeModalidades = 0;
        TabelaComPontos* tabela;
};

#endif // COMPETICAOMULTIMODALIDADES_H
