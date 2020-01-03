#include "TabelaComPontos.h"

TabelaComPontos::TabelaComPontos(Equipe** participantes, int quantidade):
                                Tabela(participantes, quantidade){
    this->quantidade = quantidade;
    this-> participantes = participantes;

    pontosOrdenados = new int[quantidade];
    pontos = new int[quantidade];
    for(int i = 0; i < quantidade; i++)
        pontos[i] = 0;

}

TabelaComPontos::~TabelaComPontos(){
    //delete[] pontos;
    //delete[] pontosOrdenados;
}

void TabelaComPontos::pontuar (Equipe* participante, int pontos){
    bool is_Participante = false;
    for(int i = 0; i < this->quantidade; i++){
        if(this->participantes[i]->getNome() == participante->getNome()){
            this->pontos[i] = this->pontos[i] + pontos;
            is_Participante = true;
        }
    }
    if(is_Participante == false)
        throw new invalid_argument("participante nao esta no vetor");
}

int TabelaComPontos::getPontos (Equipe* participante){
    for(int i = 0; i < quantidade; i++){
        if(this->participantes[i] == participante)
            return pontos[i];
    }
    throw new invalid_argument("Participante nao esta na competicao");
}

int TabelaComPontos::getPosicao(Equipe* participante){
    int temp = 0, count = 0; // Variável que receberá a posicao do participante
    bool passou = false;
    posicao = 1;

    for(int i = 0; i < quantidade; i++){
        if(pontos[i] == 0)
            count++;
        if(count == quantidade)
            throw new logic_error("Nenhum resultado definido");
    }

    for (int i = 0; i < quantidade; i++) {
        if ((this->participantes[i] == participante) && (passou == false)) {
            temp = i;
            i = 0;
            passou = true;
        }

        if ((this->pontos[i] > this->pontos[temp]) && (passou == true)) {
            posicao++;
        }
    }
    if(passou)
        return posicao;
    throw new invalid_argument("Participante nao esta na competicao");
}



Equipe** TabelaComPontos::getEquipesEmOrdem(){
    Equipe** equipesOrdenadas = new Equipe*[quantidade];
    Equipe* temporario;
    int maior;
    int temporarioPontos;

    for(int i = 0; i < quantidade; i++){
        if(pontos[i] == 0)
            count++;
        if(count == quantidade)
            throw new logic_error("Nenhum resultado definido");
        pontosOrdenados[i] = pontos[i]; //Distribui a pontuacao para o novo vetor de pontos, que sera ordenado
        equipesOrdenadas[i] = participantes[i]; //Distribui os participantes para o novo vetor que será ordenado
    }
    for(int i = 0; i < quantidade - 1; i++){
        maior = i;
        for(int j = i + 1; j < quantidade; j++){
            if(pontosOrdenados[j] > pontosOrdenados[maior])
                maior = j;
        }
        temporario = equipesOrdenadas[maior];
        temporarioPontos = pontosOrdenados[maior];

        equipesOrdenadas[maior] = equipesOrdenadas[i];
        pontosOrdenados[maior] = pontosOrdenados[i];

        equipesOrdenadas[i] = temporario;
        pontosOrdenados[i] = temporarioPontos;
    }
    return equipesOrdenadas;
}


void TabelaComPontos::imprimir(){
    Equipe** equipes = new Equipe*[quantidade];
    equipes = getEquipesEmOrdem();
    if(count != quantidade){
        for(int i = 0; i < this->quantidade; i++)
        cout << "\t" << i + 1 << "o " << equipes[i]->getNome() << "(" << pontosOrdenados[i] << "pontos)" << endl;
    }
    else{
        for(int i = 0; i < this->quantidade; i++)
                cout << participantes[i]->getNome() << endl;
    }
    delete[] equipes;
}
