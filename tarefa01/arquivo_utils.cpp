#include "arquivo_utils.h"
#include <iostream>
#include <fstream>
#include <iomanip>

std::vector<std::string> lerNomesDoArquivo(const std::string& nomeArquivo) {
    std::vector<std::string> nomes;
    std::ifstream arquivo(nomeArquivo);
    
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return nomes;
    }
    
    std::string linha;
    while (std::getline(arquivo, linha)) {
        // Remove espaços em branco no início e fim da linha
        size_t inicio = linha.find_first_not_of(" \t");
        if (inicio == std::string::npos) {
            continue; // Linha vazia ou só com espaços
        }
        
        size_t fim = linha.find_last_not_of(" \t");
        std::string nome = linha.substr(inicio, fim - inicio + 1);
        
        if (!nome.empty()) {
            nomes.push_back(nome);
        }
    }
    
    arquivo.close();
    std::cout << "Arquivo lido com sucesso! Total de nomes: " << nomes.size() << std::endl;
    return nomes;
}

void exibirNomes(const std::vector<std::string>& nomes) {
    std::cout << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ') << std::setw(20) << "LISTA DE NOMES" << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ');
    
    for (size_t i = 0; i < nomes.size(); ++i) {
        std::cout << std::setw(3) << std::right << (i + 1) 
                  << ". " << std::setw(15) << std::left << nomes[i] << std::endl;
    }
    
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ') << "Total: " << nomes.size() << " nomes" << std::endl;
    std::cout << std::endl;
}

void salvarNomesEmArquivo(const std::vector<std::string>& nomes, 
                         const std::string& nomeArquivoSaida) {
    std::ofstream arquivo(nomeArquivoSaida);
    
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao criar o arquivo de saída: " << nomeArquivoSaida << std::endl;
        return;
    }
    
    for (const std::string& nome : nomes) {
        arquivo << nome << std::endl;
    }
    
    arquivo.close();
    std::cout << "Dados salvos com sucesso no arquivo: " << nomeArquivoSaida << std::endl;
}
