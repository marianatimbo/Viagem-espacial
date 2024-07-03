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
    bool cpfValido = false;
    while(!cpfValido){
        cout << "Digite o CPF:" << endl << ">>";
        cin >> cpf;

        if(cpf.length() != 11){
            cout << "O CPF deve ter 11 dígitos. Tente novamente."<< endl;
            cout << cpf << endl;
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
    string nome;
    if(todosAstronautas.empty()){
        cout << "Nenhum astronauta foi cadastrado até o momento."<< endl;
        cout << "Deseja cadastrar um astronauta?" << endl;
        cout << "sim(1) ou não(2)" << endl;
        int escolha;
        cin >> escolha;

        if(escolha == 1){
            cadastrarAstronauta();
        }
        else{
            return;
        }

    }

    bool astroValido = false;
    while(!astroValido){
        cout << "Digite o CPF do astronauta que deseja adicionar:" << endl << ">>";
        string cpf;
        cin >> cpf;

        if(cpf.length() != 11){
            cout << "O CPF deve ter 11 dígitos. Tente novamente."<< endl;
            cout << cpf << endl;
            continue;
        }


        bool cpfExistente = false;
        for(auto& astro : todosAstronautas){
            if(astro.getCpf() == cpf){
                cpfExistente = true;
                cout << "Astronauta encontrado!" << endl;
                cout << "Nome:" << astro.getNome() << ", CPF: " << astro.getCpf() << ", Idade: " << astro.getIdade() << endl;
                
                /*se ele ta morto, fecha*/
                if(astro.getVida() == false){
                    cout << "Infelizmente este astronauta faleceu." << endl;
                    /*add algo a mais para saida*/
                    break;
                } /*se não: continua*/
                else{
                    if(astro.getDisponibilidade() == false){ /*verifica se ele tem disponibilidade*/
                        cout << "Esse astronauta está indisponível." << endl;
                        /*deseja fazer algo?*/
                        break;
                    }
                    else{
                        if(todosVoos.empty()){/*confere se tem voo disponivel para adiciona-lo*/
                            cout << "Nenhum voo foi criado até o momento. Deseja criar?" << endl;
                            cout << "Sim(1) ou não(2) " << endl << ">>";
                            int op;
                            
                            cin >> op;
                            if(op == 1){
                                cadastrarVoo();
                            }
                            else{  
                                return;
                            }
                        }

                        bool vooValido = false;
                        while(!vooValido){
                            cout << "Digite o código do voo que deseja adicioná-lo:" << endl << ">>";
                            int cod;
                            cin >> cod;

                            for(auto& voos : todosVoos){
                                if(voos.getCodigo() == cod){
                                    vooValido = true;
                                    if(voos.getStatus() != PLANEJAMENTO){
                                        cout << "Esse voo não está em planejamento." << endl;
                                        break;
                                                                              
                                    }
                                    else{
                                        voos.getPassageiros().push_back(astro);
                                        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                                        cout << "Astronauta adicionado com sucesso!" << endl;
                                        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

                                        astro.setDisponibilidade(false);
                                        astroValido = true;
                                        break;
                                    }
                                }
                            }

                            if(vooValido == false){
                                cout << "Voo não encontrado. Tente novamente." << endl;
                            }
                        }
                    }
                }
            }
        }
        
        if (!cpfExistente) {
            cout << "CPF não encontrado. Tente novamente." << endl;
        }
        else {
            astroValido = true;
        }
    }
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

