#include <iostream>
#include <list>
#include <vector>
#include "Equipe.h"
#include "TabelaComPontos.h"
#include "TabelaComOrdem.h"
#include "Modalidade.h"
#include "CompeticaoMultimodalidades.h"
#include "CompeticaoSimples.h"
#include "PersistenciaDeCompeticao.h"

using namespace std;

Equipe** preencheEquipes(int n){
    string nomeEquipe;
    Equipe** equipes = new Equipe*[n];
    for (int i = 0; i < n; i++) {
        cout << "Informe o nome da equipe " << i + 1 << ": ";
        cin >> nomeEquipe;
        equipes[i] = new Equipe(nomeEquipe);
    }
    return equipes;
}


Modalidade** compMultimodalidades(Equipe** equipes, int n, int m){

    string resultado, nomeModalidade;
    int numEquipe;
    Equipe** equipesOrdenadas = new Equipe*[n];
    Modalidade** modalidades = new Modalidade*[m];
    for(int i = 0; i < m; i++){
        if(i != 0)
            cout << endl;
        cout << "Informe o nome da modalidade " << i + 1 << ": ";
        cin >> nomeModalidade;
        modalidades[i] = new Modalidade(nomeModalidade, equipes, n);
        cout << "Tem resultado (s/n): ";
        cin >> resultado;
        if(resultado == "s"){
            for(int j = 0; j < n; j++){
                 cout << "Informe a equipe " << j + 1 << "a colocada: ";
                 cin >> numEquipe;
                 equipesOrdenadas[j] = equipes[numEquipe - 1];
            }
            modalidades[i]->setResultado(equipesOrdenadas);
        }
    //delete[] equipesOrdenadas;
    }
    return  modalidades;
}

Modalidade* compSimples(Equipe** equipes, int n){
    string resultado, nomeModalidade;
    int numEquipe;
    cout << endl << "Informe o nome da modalidade: ";
    cin >> nomeModalidade;
    Modalidade* modalidade = new Modalidade(nomeModalidade, equipes, n);
    cout << "Tem resultado (s/n): ";
    cin >> resultado;
    if(resultado == "s"){
        Equipe** equipesOrdenadas = new Equipe*[n];
        for(int i = 0; i < n; i++){
            cout << "Informe a equipe " << i + 1 << "a colocada: ";
            cin >> numEquipe;
            equipesOrdenadas[i] = equipes[numEquipe - 1];
        }
        modalidade->setResultado(equipesOrdenadas);
        //delete[] equipesOrdenadas;
    }
    return modalidade;
}

void salvaCompeticao(Competicao* competicao){
    PersistenciaDeCompeticao* persistencia = new PersistenciaDeCompeticao();
    string escolha, nomeArquivo;
    cout << endl << "Deseja salvar a competicao (s/n)? ";
    cin >> escolha;
    if(escolha == "s"){
        cout << "Digite o nome do arquivo: ";
        cin >> nomeArquivo;
        persistencia->salvar(nomeArquivo, competicao);
        //Checar se tem condicao aqui
        //SALVAR NO ARQ
    }
}

int main()
{
    try {
    int n;
    PersistenciaDeCompeticao* persistencia = new PersistenciaDeCompeticao();
    string escolha, nomeCompeticao, tipoCompeticao, nomeModalidade;

    cout << "Deseja carregar uma competicao (s/n)? ";
    cin >> escolha;

    if(escolha == "n"){
        cout << endl << "Informe a quantidade de equipes: ";
        cin >> n;

        Equipe** equipes = new Equipe*[n];
        equipes = preencheEquipes(n);

        cout << endl << "Informe o nome da competicao: ";
        cin >> nomeCompeticao;
        cout << "Competicao simples (s) ou multimodalidades (m): ";
        cin >> tipoCompeticao;
        if(tipoCompeticao == "m"){
            int m;
            cout << endl << "Informe a quantidade de modalidades: ";
            cin >> m;

            Modalidade** modalidades = new Modalidade*[m];
            modalidades = compMultimodalidades(equipes, n, m);
            CompeticaoMultimodalidades* competicao = new CompeticaoMultimodalidades(nomeCompeticao, equipes, n);
            for(int i = 0; i < m; i++){
                competicao->adicionar(modalidades[i]);
            }
            salvaCompeticao(competicao);
            competicao->imprimir();
            for(int i = 0; i < m; i++){
                modalidades[i]->~Modalidade();
            }
           // delete[] modalidades;
        }

        else /*competicao simples*/{
            CompeticaoSimples* competicao = new CompeticaoSimples(nomeCompeticao, equipes, n, compSimples(equipes, n));
            salvaCompeticao(competicao);
            competicao->imprimir();
        }
        /*
        for(int i = 0; i < n; i++){
            equipes[i]->~Equipe();
        }
        delete[] equipes;
    */
    }
    else{
        string nomeArquivo;
        cout << "Digite o nome do arquivo: ";
        cin >> nomeArquivo;
        persistencia->carregar(nomeArquivo)->imprimir();
        //ver se precisa checar se arq existe
        //LER ARQUIVO E RETORNAR COMPETICAO
        //IMPRIMIR A COMPETICAO GERADA
    }

    }catch(logic_error *e){
        cout << e->what() << endl;
    }catch(invalid_argument *e){
        cout << e->what() << endl;
    }
    return 0;
}
