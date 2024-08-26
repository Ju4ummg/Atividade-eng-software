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

# Composição e herança

Composição é um princípio onde uma classe é composta de uma ou mais instâncias de outras classes, formando uma relação "tem um". Em vez de uma classe herdar atributos e métodos de outra, ela contém objetos de outras classes. Já a herança é um mecanismo que permite criar uma nova classe baseada em uma classe existente, herdando seus atributos e métodos.
 
## Classe que não segue o princípio

```Cpp
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

```

## Classe corrigida

Classe corrigida com herança:

```Cpp
class Motor {
public:
    Motor(std::string tipo) : tipo(tipo) {}

    void ligar() {
        std::cout << "Motor " << tipo << " ligado." << std::endl;
    }

    void desligar() {
        std::cout << "Motor " << tipo << " desligado." << std::endl;
    }

private:
    std::string tipo;
};

class Carro : public Motor {
public:
    Carro(std::string tipo, std::string modelo) : Motor(tipo), modelo(modelo) {}

    void ligar() {
        Motor::ligar();
        std::cout << "Carro modelo " << modelo << " ligado." << std::endl;
    }

    void desligar() {
        Motor::desligar();
        std::cout << "Carro modelo " << modelo << " desligado." << std::endl;
    }

private:
    std::string modelo;
};
```

Classe corrigida com composição:

```Cpp
class Motor {
public:
    Motor(std::string tipo) : tipo(tipo) {}}
```

# Princípio da responsabilidade única:

O Princípio da Responsabilidade Única (SRP - Single Responsibility Principle) afirma que uma classe deve ter apenas uma única razão para mudar, ou seja, ela deve ter apenas uma responsabilidade ou função específica.

## Classe que não segue o princípio:
```Cpp
class Relatorio {
public:
    Relatorio(std::string conteudo) : conteudo(conteudo) {}

    void gerarRelatorio() {
        std::cout << "Gerando relatório..." << std::endl;
        std::cout << conteudo << std::endl;
        salvarRelatorio();
    }

    void salvarRelatorio() {
        std::ofstream arquivo("relatorio.txt");
        if (arquivo.is_open()) {
            arquivo << conteudo;
            arquivo.close();
        } else {
            std::cerr << "Não foi possível abrir o arquivo para escrita." << std::endl;
        }
    }

private:
    std::string conteudo;
};
```

## Classe corrigida

```Cpp
class Relatorio {
public:
    Relatorio(std::string conteudo) : conteudo(conteudo) {}

    void gerarRelatorio() {
        std::cout << "Gerando relatório..." << std::endl;
        std::cout << conteudo << std::endl;
    }

    std::string getConteudo() const {
        return conteudo;
    }

private:
    std::string conteudo;
};

class GerenciadorDeArquivo {
public:
    static void salvar(const std::string& conteudo, const std::string& caminho) {
        std::ofstream arquivo(caminho);
        if (arquivo.is_open()) {
            arquivo << conteudo;
            arquivo.close();
        } else {
            std::cerr << "Não foi possível abrir o arquivo para escrita." << std::endl;
        }
    }
};
```
