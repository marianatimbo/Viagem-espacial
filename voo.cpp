#include "voo.h"

int voo::getCodigo(){
    return this->codigo;
}

StatusVoo voo::getStatus(){
    return this->status;
}

list<astronauta> voo::getPassageiros(){
    return this->passageiros;
}

voo::voo(int codigo_, StatusVoo status_){
    this->codigo = codigo_;
    this->status = status_;
}