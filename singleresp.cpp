#include <iostream>
#include <string>
#include <fstream>

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