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

# Princípio aberto/fechado

O princípio aberto/fechado diz que uma classe deve ser fechada para modificações e abertas
para extensões, ou seja, ela deve estar preparada caso uma subclasse dela precise de
modificações e adaptações

## Classe que não segue o princípio

A classe a seguir não segue o princípio aberto/fechado pois se quisermos adicionar um novo tipo de forma, como um triângulo, teríamos que modificar a classe Drawing para lidar com essa nova forma

```Cpp
class Drawing {
private:
    std::vector<Shape*> shapes;

public:
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    void drawAllShapes() const {
        for (const auto& shape : shapes) {
            shape->draw();
        }
    }

    //na main deveriamos modificar aqui
};
```

## Correção da classe

Agora com a adicão da classe 'Triangle' não precisamos modificar a classe Drawing para lidar com essa nova forma

```Cpp
class Triangle : public Shape {
public:
    void draw() const override {
        std::cout << "Desenhando um triângulo." << std::endl;
    }
};
```
