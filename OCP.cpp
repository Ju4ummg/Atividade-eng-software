#include <iostream>
#include <vector>
//adesão ao princípio OCP

class Shape {
public:
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Desenhando um círculo." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Desenhando um quadrado." << std::endl;
    }
};

class Triangle : public Shape {
public:
    void draw() const override {
        std::cout << "Desenhando um triângulo." << std::endl;
    }
};

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
};