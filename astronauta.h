#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>
#include <list>
#include "administracao.h"

using namespace std;
using std::string;


class astronauta {
    private:
        string nome;
        string cpf;
        int idade;

        bool disponibilidade;
        bool vida; 
        
        adm voosParticipados;


    public:
        void cadastrarAstronauta();
        void listarAstronautasMortos();
};

#endif