#include <string>
using std::string;

class astronauta {
    private:
        string nome;
        string cpf;
        int idade;
        int vida; // vivo(1) ou morto(0).

    public:
        void cadastrarAstronauta();
        void listarAstronautasMortos();
};

class voo{
    private:
        int codigo;
        astronauta piloto1;
        astronauta piloto2; /**/
        int status; // planejamento, em curso, fizalizado ou explodido.

        // lista de astronauta passageiros;
        // status do voo;
    public:
        void cadastrarVoo();
        void adicionarAstro();
        void removerAstro();
        void lancarVoo();
        void explodirVoo();
        void finalizarVoo();
        void listarVoos();
};
