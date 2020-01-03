#include "TabelaComOrdem.h"

TabelaComOrdem::TabelaComOrdem(Equipe** participantes, int quantidade) :
                               Tabela(participantes, quantidade){
    this->participantes = participantes;
    this->quantidade = quantidade;
    equipesOrdenadas = new Equipe*[quantidade];
    if(quantidade < 2){
        throw new invalid_argument("Quantidade de equipes insuficiente");
    }
}

TabelaComOrdem::~TabelaComOrdem()
{
    delete[] equipesOrdenadas;
}

void TabelaComOrdem::setResultado (Equipe** ordem){
    equipesOrdenadas = ordem;
    resultado = true;
}
int TabelaComOrdem::getPosicao(Equipe* participante){
    if(!resultado)
        throw new logic_error("Nenhum resultado definido");

    for(int i = 0; i < quantidade; i++){
        if(equipesOrdenadas[i] == participante){
            return i + 1;
        }
    }
    throw new invalid_argument("Participante nao esta na competicao");
}

Equipe** TabelaComOrdem::getEquipesEmOrdem(){
    if(resultado)
        return equipesOrdenadas;
    throw new logic_error("Nenhum resultado definido");
}

void TabelaComOrdem::imprimir(){
    if(resultado){
        for(int i = 0; i < this->quantidade; i++)
            cout << "\t" << i + 1 << "o " << equipesOrdenadas[i]->getNome() << endl;
    }
    else{
        for(int i = 0; i < this->quantidade; i++)
            cout << "\t"  << participantes[i]->getNome() << endl;
    }
}
