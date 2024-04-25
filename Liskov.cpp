// Exemplo de aderência ao LSP
class Bird {
    // ...
};

class FlyingBird : public Bird {
public:
    virtual void fly() = 0;
};

class Ostrich : public Bird {
    // Ostrich não pode voar, então não herda de FlyingBird
};