#include <iostream>
#include <string>
#include "administracao.h"
#include <list>
using namespace std;

void adm::cadastrarAstronauta(){
    string name, cpf;
    int age;

    cout << "Digite o nome do novo astronauta:" << endl << ">>";
    cin >> name;
    /*sem ponto, revisar erro de espaço*/
    cpf = validarCpf();

    cout  << "Digite a idade:" << endl << ">>";
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

void adm::adicionarAstro(){
    string nome, cpf;

    cout << "Digite o nome do astronauta que deseja adicionar:" << endl << ">>";
    cin >> nome;
    
    cpf = validarCpf();
    
    /*
    1) if nenhum astronauta cadastrado; deseja cadastrar?
    2) pedir nome e cpf para adicionar;
    3) astronauta nao cadastrado, cadastrar? ;
    3:) observar se esta disponivel, caso exista o astronauta;
    3::) observar se ele esta vivo;
    4) pedir codigo do voo;
    5) Verificar se existe o voo e esta em planejamento;
    6) se existe voo, deseja criar? ;

    */
}


void removerAstro(){
    /*
    0) if nenhuma voo cadastrado; deseja criar?;
    1) pedir codigo do voo;
    1:) verificar se esse voo existe;
    1::) verificar se o voo esta em planejameto;
    2) pedir dados do astronauta;
    2:) verificar se ele existe, se  esta vivo e se faz parte do voo;
    3) mudar status de disponibilidade do astronuta e tira-lo do voo;
    */
}

void adm::listarAstronautasMortos(){
    for (auto& astro : todosAstronautas) {
        cout << "Nome: " << astro.getNome() << ", Idade: " << astro.getIdade() << ", cpf: " << astro.getCpf() << endl;
    }
    
    /*
    cpf, nome, voos que participou;
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

