#ifndef ADMINISTRACAO_H
#define ADMINISTRACAO_H

#include <string>
#include <list>
#include "voo.h"
#include "astronauta.h"

using namespace std;

class adm {
    private:
        list<astronauta> todosAstronautas;
        list<voo> todosVoos;

    public:
        void cadastrarAstronauta();
        void cadastrarVoo();

        void adicionarAstro();
        void removerAstro();
        void lancarVoo();

        void explodirVoo();
        void finalizarVoo();
        void listarVoos();
        void listarAstronautasMortos();   
        
        string validarCpf(){
            string cpf;
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

            return cpf;
        }  
};

#endif