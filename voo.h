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
    
};

#endif
