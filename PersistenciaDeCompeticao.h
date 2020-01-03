#ifndef PERSISTENCIADECOMPETICAO_H
#define PERSISTENCIADECOMPETICAO_H

#include <iostream>
#include <string>
#include <fstream>
#include "Competicao.h"
#include "CompeticaoSimples.h"
#include "CompeticaoMultimodalidades.h"
#include "Modalidade.h"

using namespace std;

class PersistenciaDeCompeticao
{
    public:
        PersistenciaDeCompeticao();
        virtual ~PersistenciaDeCompeticao();
        Competicao* carregar(string arquivo);
        void salvar(string arquivo, Competicao* c);

    protected:
        string arquivo;
        Competicao* c;
};

#endif // PERSISTENCIADECOMPETICAO_H
