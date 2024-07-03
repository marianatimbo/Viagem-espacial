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
        voo(int codigo_, StatusVoo status_);

        int getCodigo();
        StatusVoo getStatus();
        list<astronauta> getPassageiros();

        bool astroEncontrado(const string& cpf);
        void removerTripulante(string cpf);

        list<astronauta> listarPassageiros(){
            return passageiros;
        };

        void botarAstro(astronauta astro){
            passageiros.push_back(astro);
        }


};

#endif
