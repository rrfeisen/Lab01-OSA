
#include <iostream>
#include <vector>
#include <string>
#include "arquivo_utils.h"

int main() {
    // Nome dos arquivos de entrada e saída
    const std::string arquivoEntrada = "nomes.txt";
    const std::string arquivoSaida = "nomes_saida.txt";
    
    std::cout << "=== TAREFA 1: LEITURA DE ARQUIVO COM REGISTROS SIMPLES ===" << std::endl;
    std::cout << std::endl;
    
    // Ler os nomes do arquivo de entrada
    std::cout << "Lendo nomes do arquivo: " << arquivoEntrada << std::endl;
    std::vector<std::string> nomes = lerNomesDoArquivo(arquivoEntrada);
    
    // Verificar se a leitura foi bem-sucedida
    if (nomes.empty()) {
        std::cout << "Nenhum nome foi lido do arquivo." << std::endl;
        std::cout << "Certifique-se de que o arquivo '" << arquivoEntrada 
                  << "' existe e contém dados válidos." << std::endl;
        return 1;
    }
    
    // Exibir os nomes na tela de forma formatada
    exibirNomes(nomes);
    
    // Salvar os nomes em um arquivo de saída
    std::cout << "Salvando nomes no arquivo: " << arquivoSaida << std::endl;
    salvarNomesEmArquivo(nomes, arquivoSaida);
    
    std::cout << std::endl << "Programa executado com sucesso!" << std::endl;
    
    return 0;
}