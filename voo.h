#ifndef VOO_H
#define VOO_H

#include <string>
#include <list>
#include "astronauta.h"

using namespace std;
using std::string;

enum StatusVoo {
    PLANEJAMENTO,
    EM_CURSO,
    FINALIZADO,
    EXPLODIDO
};

class voo {
    private:
        int codigo;
        list<astronauta> passageiros;
        StatusVoo status;

    public:
        void cadastrarVoo();
        void adicionarAstro();
        void removerAstro();
        void lancarVoo();
        void explodirVoo();
        void finalizarVoo();
        void listarVoos();
};

#endif
