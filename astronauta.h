#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>
#include <list>

using namespace std;
using std::string;


class astronauta {
    private:
        string nome;
        string cpf;
        int idade;

        bool disponibilidade;
        bool vida; 

        list<int> voosParticipados; /*receber codigo*/

    public:
       
};

#endif