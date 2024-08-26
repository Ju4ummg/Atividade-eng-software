#include <iostream>
#include <string>

class Motor {
public:
    Motor(std::string tipo) {
        tipo = tipo;  // Erro: Atribuição incorreta ao próprio parâmetro em vez de ao membro da classe
    }

    void ligar() {
        std::cout << "Motor " << tipo << " ligado." << std::endl;  // Erro: `tipo` não foi armazenado corretamente
    }

    void desligar() {
        std::cout << "Motor " << tipo << " desligado." << std::endl;  // Erro: `tipo` não foi armazenado corretamente
    }

private:
    std::string tipo;
};

class Carro : public Motor {
public:
    Carro(std::string tipo, std::string modelo) : Motor(tipo) {
        modelo = modelo;  // Erro: Atribuição incorreta ao próprio parâmetro em vez de ao membro da classe
    }

    void ligar() {
        ligar();  // Erro: Chamada recursiva infinita; deveria usar `super::ligar()` ou `Motor::ligar()`
        std::cout << "Carro modelo " << modelo << " ligado." << std::endl;  // Erro: `modelo` não foi armazenado corretamente
    }

    void desligar() {
        desligar();  // Erro: Chamada recursiva infinita; deveria usar `super::desligar()` ou `Motor::desligar()`
        std::cout << "Carro modelo " << modelo << " desligado." << std::endl;  // Erro: `modelo` não foi armazenado corretamente
    }

private:
    std::string modelo;
};

int main() {
    Carro carro("V8", "Mustang");
    carro.ligar();  // Isso causará um loop infinito
    carro.desligar();  // Isso causará um loop infinito
    return 0;
}
