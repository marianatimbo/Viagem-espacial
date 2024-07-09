#include <iostream>
#include <string>
#include "../class/administracao.h"
#include <list>

using namespace std;

void adm::cadastrarAstronauta(){
    string name, cpf;
    int age;
    
    cout << "=-=-=-= OPERAÇÃO CADASTRAR ASTRONAUTA =-=-=-=-=" << endl;
    
    cout << "Digite o nome do novo astronauta:" << endl << ">>";
    cin.ignore();
    getline(cin, name);
    
    bool cpfValido = false;
    while(!cpfValido){
        cout << "Digite o CPF com apenas números:" << endl << ">>";
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

    
    bool idadeValida = false;
    while(!idadeValida){
        cout  << "Digite a idade:" << endl << ">>";
        cin >> age;
        if(age < 18){
            cout << "A idade mínima é 18. Tente novamente.\n";
        }
        else{
            idadeValida = true;
        }
    }

    astronauta novoAstronauta(name, cpf, age, true, true);
    todosAstronautas.push_back(novoAstronauta);
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Astronauta cadastrado com sucesso!" << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

}

void adm::cadastrarVoo(){
    int cod;
    cout << "=-=-=-= OPERAÇÃO CADASTRAR VOO =-=-=-=" << endl;

    bool codValido = false;
    while(!codValido){
        cout << "Digite o código do voo que deseja criar:" << endl << ">>";
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
    cout << "=-= OPERAÇÃO ADICIONAR ASTRONAUTA EM VOO =-=" << endl;
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
        cout << "Digite o CPF do astronauta que deseja adicionar com apenas números:" << endl << ">>";
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
                cout << "-> Nome: " << astro.getNome() << endl;
                cout << "-> CPF: " << astro.getCpf() << endl;
                cout << "-> Idade: " << astro.getIdade() << endl;
                
                if(astro.getVida() == false){
                    cout << "Infelizmente este astronauta faleceu." << endl;
                    break;
                }
                else{
                    
                    if(todosVoos.empty()){
                        cout << "Nenhum voo foi criado até o momento. Deseja criar?" << endl;
                        cout << "Sim(1) ou não(2)" << endl << ">>";
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
                                if(voos.astroEncontrado(astro.getCpf()) == true){
                                    cout << "Esse astronauta já está cadastrado no voo.\n";
                                    break;
                                }

                                if(voos.getStatus() != PLANEJAMENTO){
                                    cout << "Esse voo não está em planejamento." << endl;
                                    break;
                                                                          
                                }
                                else{
                                    voos.botarAstro(astro);
                                    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                                    cout << "Astronauta adicionado com sucesso!" << endl;
                                    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

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
        
        if (!cpfExistente) {
            cout << "CPF não encontrado. Tente novamente." << endl;
        }
        else {
            astroValido = true;
        }
    }
}

void adm::removerAstro(){
    cout << "=-=-= OPERAÇÃO REMOVER ASTRONAUTA DE VOO =-=-=-=" << endl;
    
    if(todosAstronautas.empty()){
        cout << "Nenhum astronauta foi cadastrado até o momento."<< endl;
        return;
    }
    else if(todosVoos.empty()){
        cout << "Nenhum voo foi cadastrado até o momento." << endl;
        return;
    }

    bool astroValido = false;
    while(!astroValido){
        string cpf;
        cout << "Digite o CPF do astronauta com apenas números:" << endl << ">>";
        cin >> cpf;

        if(cpf.length() != 11){
            cout << "O CPF deve ter 11 dígitos. Tente novamente."<< endl;
            cout << cpf << endl;
            continue;
        }

        bool cpfExistente;
        for(auto& astro : todosAstronautas){
            if(astro.getCpf() == cpf){
                cpfExistente = true;
                cout << "Astronauta encontrado!" << endl;
                cout << "-> Nome:" << astro.getNome() << "\n-> CPF: " << astro.getCpf() << "\n-> Idade: " << astro.getIdade() << endl;

                bool vooValido = false;
                while(!vooValido){
                    cout << "Digite o código do voo que deseja removê-lo:\n" << ">>" << endl;
                    int cod;
                    cin >> cod;

                    for(auto& voo : todosVoos){
                        if(voo.getCodigo() == cod){
                            vooValido = true;

                            if(voo.getStatus() != PLANEJAMENTO){
                                cout << "Esse voo não está disponivel para modificações." << endl;
                                break;
                            }
                            else{
                                if(voo.astroEncontrado(cpf) == true){
                                    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                                    cout << "Astronauta localizado e removido com sucesso!" << endl;
                                    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

                                    voo.removerTripulante(cpf);
                                    break;
                                }
                                else{
                                    cout << "Astronauta não está no voo." << endl;
                                    break;
                                }
                            }
                        }
                    }

                    if(vooValido == false){
                        cout << "Voo não encontrado. Tente novamente." << endl;
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

void adm::lancarVoo(){
    cout << "=-=-=-= OPERAÇÃO LANÇAR VOO =-=--=-=\n";
    if(todosVoos.empty()){
        cout << "Nenhum voo foi cadastrado até o momento.\n";
        return;
    } 

    
    bool vooValido = false;
    while(!vooValido){
        cout << "Digite o código do voo:\n" << ">>";
        int cod;
        cin >> cod;

        for(auto& voo : todosVoos){
            if(voo.getCodigo() == cod){
                vooValido = true;
                
                if(voo.getStatus() == PLANEJAMENTO){
                    if(voo.getPassageiros().empty()){
                        cout << "Nenhum astronauta foi cadastrado nesse voo\n";
                        break;

                    }
                    else{
                        bool astroValido = true;
                        for(auto& astroGlobal : todosAstronautas){
                            for(auto astroPassa : voo.getPassageiros()){
                                if(astroGlobal.getCpf() == astroPassa.getCpf() && astroGlobal.getDisponibilidade() == false){
                                    cout << "Astronauta de CPF " << astroGlobal.getCpf() << " indiponível para lançamento\n";
                                    astroValido = false;
                                }
                            }
                        }
                        if(astroValido == false){
                            break;
                        }
                        else{
                            for(auto& astroGlobal : todosAstronautas){
                                for(auto& astroPassa : voo.getPassageiros()){
                                    if(astroGlobal.getCpf() == astroPassa.getCpf()){
                                        astroGlobal.setDisponibilidade(false);
                                        astroGlobal.adicionarVoo(cod);
                                    }
                                }
                            }

                            cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                            cout << "Voo lançado com sucesso!\n";
                            cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;     
                            voo.mudarStatus(EM_CURSO);    
                            break;                   
                        }
                    }
                }
                else{
                    cout << "Este voo já foi lançado.\n";
                    break;
                }
            }
        }

        if(vooValido == false){
            cout << "Código inválido, tente novamente.\n";
        }
    }
}

void adm::explodirVoo(){
    cout << "=-=-=-= OPERAÇÃO EXPLODIR VOO =-=-=-=\n";
    if(todosVoos.empty()){
        cout<< "Nenhum voo foi criado.\n";
        return;
    }
    bool vooValido = false;
    while(!vooValido){
        cout << "Digite o código do voo que deseja explodir:\n" << ">>";
        int cod;
        cin >> cod;

        for(auto& voo : todosVoos){
            if(voo.getCodigo() == cod){
                vooValido = true;

                if(voo.getStatus() != EM_CURSO){
                    cout << "Esse voo não está em curso para ser detonado.\n";
                    break;
                }
                else{
                    voo.mudarStatus(EXPLODIDO);
                    for(auto& astroGlobal : todosAstronautas){
                        for(auto& astroPassa : voo.getPassageiros()){
                            if(astroGlobal.getCpf() == astroPassa.getCpf()){
                                astroGlobal.setVida(false);
                            }
                        }
                    }
                    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                    cout << "Voo explodidio com sucesso!\n";
                    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                    break;
                }
            }
        }
        if(vooValido == false){
            cout << "Código inválido, tente novamente.\n";
        }
    }
}

void adm::finalizarVoo(){
    cout << "=-=-=-=-= OPERAÇÃO FINALIZAR VOO =-=-=-=-=\n";
    if(todosVoos.empty()){
        cout << "Nenhum voo foi criado até o momento.\n";
        return;
    }

    bool vooValido = false;
    while(!vooValido){
        cout << "Digite o código do voo que deseja finalizar:\n" << ">>";
        int cod;
        cin >> cod;

        for(auto& voo : todosVoos){
            if(voo.getCodigo() == cod){
                vooValido = true;

                if(voo.getStatus() != EM_CURSO){
                    cout << "Esse voo não está em curso para ser finalizado.\n";
                    break;
                }
                else{
                    voo.mudarStatus(FINALIZADO);
                    for(auto& astroGlobal : todosAstronautas){
                        for(auto& astroPassa : voo.getPassageiros()){
                            if(astroGlobal.getCpf() == astroPassa.getCpf()){
                                astroGlobal.setDisponibilidade(true);
                            }
                        }
                    }

                    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                    cout << "Voo finalizado com sucesso.\n";
                    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                    break;
                }
            }
        }
        if(vooValido == false){
            cout << "Código inválido, tente novamente.\n";
        }

    }
}

void adm::listarVoos(){
    cout << "=-=-=-=- OPERAÇÃO LISTAR VOOS =-=-=-=-=" << endl;
    if(todosVoos.empty()){
        cout << "Nenhum voo foi criado até o momento\n";
        return;
    }

    for(auto& voo : todosVoos){
        if(voo.getStatus() == PLANEJAMENTO){
            cout << "#### Código: " << voo.getCodigo() << " ####" << endl;
            cout << "-> EM PLANEJAMENTO <-\n"; 
            if(voo.getPassageiros().empty()){
                cout << "-> Nenhum astronauta cadastrado até o momento.\n\n";
            }
            else{
                int cont = 0;
                for(auto& astro : voo.getPassageiros()){
                    cont++;
                    cout << "Astronauta " << cont << ":\n";
                    cout << "-> Nome: " << astro.getNome() << endl;
                    cout << "-> CPF: " << astro.getCpf() << endl;
                    cout << "-> Idade: " << astro.getIdade() << endl;
                    cout << "\n";
                }
            }

        }
    }
    for(auto& voo : todosVoos){
        if(voo.getStatus() == EM_CURSO){
            cout << "#### Código: " << voo.getCodigo() << " ####" << endl;
            cout << "-> EM CURSO <-\n";
            int cont = 0;
            for(auto& astro : voo.getPassageiros()){
                cont++;
                cout << "Astronauta " << cont << ":\n";
                cout << "-> Nome: " << astro.getNome() << endl;
                cout << "-> CPF: " << astro.getCpf() << endl;
                cout << "-> Idade: " << astro.getIdade() << endl;
                cout << "\n";
            }
        }
    }
    for(auto& voo : todosVoos){
        if(voo.getStatus() == FINALIZADO || voo.getStatus() == EXPLODIDO){
            cout << "#### Código: " << voo.getCodigo() << " ####" << endl;
            if(voo.getStatus() == FINALIZADO){
                cout << "-> FINALIZADO COM SUCESSO\n";
            }
            else{
                cout << "-> FINALIZADO SEM SUCESSO\n";
            }
            int cont = 0;
            for(auto& astro : voo.getPassageiros()){
                cont ++;
                cout << "Astronauta " << cont << ":\n";
                cout << "-> Nome: " << astro.getNome() << endl;
                cout << "-> CPF: " << astro.getCpf() << endl;
                cout << "-> Idade: " << astro.getIdade() << endl;
                cout << "\n";
            }
        }
    }
}

void adm::listarAstronautasMortos(){
    cout << "=-=-=-= OPERAÇÃO LISTAR ASTRONAUTAS MORTOS =-=-=-=\n";
    if(todosAstronautas.empty()){
        cout << "Nenhum astronauta cadastrado até o momento.\n";
        return;
    }
    for (auto& astro : todosAstronautas) {
        if(astro.getVida() == false){
            cout << "-> Nome: " << astro.getNome() << "\n-> CPF: " << astro.getCpf() << "\n-> Idade: " << astro.getIdade() << endl;
            cout << "-> Voos participados:" << endl;
            for(auto& voo : astro.listarVoos()){
                cout << "-> Código:" << voo << endl;
            }
            cout << "\n";
        }
        
    }

}

