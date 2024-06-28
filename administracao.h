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

    // metodos  que manipulam as listas, como cadastrar novo astronauta, matar astronauta, cadastrar astronauta em um voo, etc.
    void cadastrarAstronauta();
    void cadastrarVoo();

    void listarAstronautasMortos();

    void lancarVoo();

    void adicionarAstro();
    void removerAstro();
    void explodirVoo();
    void finalizarVoo();
    void listarVoos();

};

#endif