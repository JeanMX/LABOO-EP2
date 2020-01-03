#include "Tabela.h"

Tabela::Tabela(Equipe** participantes, int quantidade):
                participantes(participantes), quantidade(quantidade){
    if(quantidade < 2)
        throw new invalid_argument ("Quantidade de equipes insuficiente");

}

Tabela::~Tabela()
{}

int Tabela::getQuantidadeDeEquipes(){
    return quantidade;
}
