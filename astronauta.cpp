#include "astronauta.h"
using namespace std;

astronauta::astronauta(string nome_, string cpf_, int idade_, bool dispo, bool vida){
    this->nome = nome_;
    this->cpf = cpf_;
    this->idade = idade_;
    this->disponibilidade = dispo;
    this->vida = vida;
}

string astronauta::getNome(){
    return this->nome;
}

string astronauta::getCpf(){
    return this->cpf;
}

int astronauta::getIdade(){
    return this->idade;
}

bool astronauta::getDisponibilidade(){
    return this->disponibilidade;
}

bool astronauta::getVida(){
    return this->vida;
}