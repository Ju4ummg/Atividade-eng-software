// Exemplo de violação do LSP
#include <stdexcept>

class Bird {

public:
    virtual void fly() = 0;

};

class Ostrich : public Bird {

public:
    
    void fly() override {
        
        throw std::runtime_error("Ostrich can't fly!");
    
    }

};
