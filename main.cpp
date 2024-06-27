#include <iostream>
#include <string>
#include "astronauta.h"
#include "voo.h"
#include <list>

using namespace std;
using std::string;

void imprimeMenu(){
    cout << "\n --------MENU----------\n";
    cout << "Selecione uma das opções abaixo:\n";
    cout << "(1) Cadastrar astronauta\n";
    cout << "(2) Cadastrar voo\n";
    cout << "(3) Adicionar astronauta em voo\n";
    cout << "(4) Remover Astronauta de um voo\n";
    cout << "(5) Lançar voo\n";
    cout << "(6) Explodir voo\n";
    cout << "(7) Finalizar voo\n";
    cout << "(8) Listar todos os voos\n";
    cout << "(9) Listar todos os astronautas mortos\n";
    cout << "(10) Finalizar operação\n";
    cout << ">> ";
}

int main(){
    int opcao;

    do{
        imprimeMenu();
        cin >> opcao;

        switch(opcao){
            case 1: /*Cadastrar astronauta*/ break;
            case 2: /*Cadastrar voo*/ break;
            case 3: /*Adicionar astronauta em voo*/ break;
            case 4: /*Remover Astronauta de um voo*/ break;
            case 5: /*Lançar voo*/ break;
            case 6: /*Explodir voo*/ break;
            case 7: /*Finalizar voo*/ break;
            case 8: /*Listar todos os voos*/ break;
            case 9: /*Listar todos os astronautas mortos*/ break;
            case 10: /*Finalizar operação*/ break;

            default: cout <<"\nOpção inválida, tente novamente.\n";
        }

    } while(opcao != 10);
    

    return 0;
}