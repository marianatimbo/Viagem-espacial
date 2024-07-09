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
        
};

#endif