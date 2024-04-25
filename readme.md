# Princípio de substituição de Liskov

O princípio de substituição de Liskov é o princípio que afirma que se S é um subtipo de 
T, então os objetos do tipo T podem ser substituidos pelos objetos do tipo S sem alterar
nenhuma das propriedades desejaveis do programa

## Classe que não segue o princípio

A classe feita não segue o princípio de Liskov pois a classe 'Ostich' não consegue substituir a classe base 'Bird' em todos os contextos, porque o método 'fly' da classe 'Ostrich' lança uma exceção.

```Cpp
class Ostrich : public Bird {

public:
    
    void fly() override {
        
        throw std::runtime_error("Ostrich can't fly!");
        //é esperado que nada aconteça, mas a classe lança uma exceção
    
    }

};
```

## Correção da classe

A classe após a correção de Liskov agora pode ser substituido sem alterar nenhuma das propriedades do programa

```Cpp
class Ostrich : public Bird {
    // Ostrich não pode voar, então não herda de FlyingBird
};
```