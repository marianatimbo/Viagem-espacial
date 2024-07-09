#include "../class/voo.h"

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

void voo::mudarStatus(StatusVoo status_){
    this->status = status_;
}

bool voo::astroEncontrado(const string& cpf){
    for(auto& astro : passageiros){
        if(astro.getCpf() == cpf){
            return true;
        }
    }
    return false;
}

void voo::removerTripulante(string cpf) {
    passageiros.remove_if([&cpf](astronauta& astro) {
        return astro.getCpf() == cpf;
    });
}

