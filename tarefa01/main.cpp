
#include <iostream>
#include <vector>
#include <string>
#include "arquivo_utils.h"
using namespace std;
int main() {
    // Nome dos arquivos de entrada e saída
    const string arquivoEntrada = "Arquivo_Nomes.txt";
    const string arquivoSaida = "nomes_saida.txt";
    
    cout << "=== TAREFA 1: LEITURA DE ARQUIVO COM REGISTROS SIMPLES ===" << endl;
    cout << endl;
    
    // Ler os nomes do arquivo de entrada
    cout << "Lendo nomes do arquivo: " << arquivoEntrada << endl;
    vector<string> nomes = lerNomesDoArquivo(arquivoEntrada);
    
    // Verificar se a leitura foi bem-sucedida
    if (nomes.empty()) {
        cout << "Nenhum nome foi lido do arquivo." << endl;
        cout << "Certifique-se de que o arquivo '" << arquivoEntrada 
                  << "' existe e contém dados válidos." << endl;
        return 1;
    }
    
    // Exibir os nomes na tela de forma formatada
    exibirNomes(nomes);
    
    // Salvar os nomes em um arquivo de saída
    cout << "Salvando nomes no arquivo: " << arquivoSaida << endl;
    salvarNomesEmArquivo(nomes, arquivoSaida);
    
    cout << endl << "Programa executado com sucesso!" << endl;
    
    return 0;
}
