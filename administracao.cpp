#include <iostream>
#include <string>
#include "administracao.h"
#include <list>
using namespace std;

void adm::cadastrarAstronauta(){
    string name, cpf;
    int age;

    cout << "Digite o nome do novo astronauta:" << endl << ">> ";
    cin >> name;

    bool cpfValido = false;
    while(!cpfValido){
        cout << "Digite o CPF:" << endl << ">> ";
        cin >> cpf;

        if(cpf.length() != 11){
            cout << "O CPF deve ter 11 dígitos. Tente novamente."<< endl;
            continue;
        }

        bool cpfExistente = false;
        for( auto& astro : todosAstronautas){
            if(astro.getCpf() == cpf){
                cout << "Esse CPF já está cadastrado. Tente novamente." << endl;
                cpfExistente = true;
                break;
            }
        }

        if(!cpfExistente){
            cpfValido = true;
        }
    }

    cout  << "Digite a idade:" << endl << ">> ";
    cin >> age;

    astronauta novoAstronauta(name, cpf, age, true, true);
    todosAstronautas.push_back(novoAstronauta);
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Astronauta cadastrado com sucesso!" << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

}


void adm::cadastrarVoo(){
    int cod;

    bool codValido = false;
    while(!codValido){
        cout << "Digite o código do voo que deseja criar:" << endl << ">> ";
        cin >> cod;

        codValido = true;
        for(auto& voo : todosVoos){
            if(voo.getCodigo() == cod){
                cout << "Esse código já existe. Tente novamente." << endl;
                codValido = false;
                break;
            }
        }
    }   
    

    voo novoVoo(cod, PLANEJAMENTO);
    todosVoos.push_back(novoVoo);
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Voo cadastrado com sucesso!" << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    
}

void adm::listarAstronautasMortos(){
    for (auto& astro : todosAstronautas) {
        cout << "Nome: " << astro.getNome() << ", Idade: " << astro.getIdade() << ", cpf: " << astro.getCpf() << endl;
    }
    
    /*
    cpf, nome, voos que participou;
    */
}

void adicionarAstroEmVoo(){
    /*
    
    Verificar se existe voo disponivel em planejamento; se nao deseja criar;

    astronauta nao cadastrado, ja foi cadastrado;
    voo nao existe;

    observar se esta disponivel;
    observar se ele esta vivo;

    */
}

void removerAstro(){
    /*
    
    Verificar se o voo esta em planejamento;

    astronauta nao cadastrado;
    voo nao existe;

    mudar status de disponibilidade;
    */
}

void lancarVoo(){
    /*
    
    verificar se ha astronautas no voo (pelo menos 1) e 
    verificar esta todos disponiveis;

    mudar status de disponibilidade; 
    
    */
}

void explodirVoo(){
    /*
    mudar estado de vida de todos os astronautas;

    adicionar na lista de mortos e de voos;
    mudar status do voo;

    
    */
}

void finalizarVoo(){
    /*
    mudar disponibilidade;
    mudar status;
    adicionar a lista de voos;    
    
    */
}

void listarVoos(){
    /*
    em planejamento e seus astronautas;
    em curso ||;
    finalizados || com sucesso ou nao;
    
    */   
}

