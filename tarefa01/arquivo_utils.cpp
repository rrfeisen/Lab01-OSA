#include "arquivo_utils.h"

vector<string> lerNomesDoArquivo(const string& nomeArquivo) {
    vector<string> nomes;
    ifstream arquivo(nomeArquivo);
    
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return nomes;
    }
    
    string linha;
    while (getline(arquivo, linha)) {
        // Remove espaços em branco no início e fim da linha
        size_t inicio = linha.find_first_not_of(" \t");
        if (inicio == string::npos) {
            continue; // Linha vazia ou só com espaços
        }
        
        size_t fim = linha.find_last_not_of(" \t");
        string nome = linha.substr(inicio, fim - inicio + 1);
        
        if (!nome.empty()) {
            nomes.push_back(nome);
        }
    }
    
    arquivo.close();
    cout << "Arquivo lido com sucesso! Total de nomes: " << nomes.size() << endl;
    return nomes;
}

void exibirNomes(const vector<string>& nomes) {
    cout << endl;
    cout << setfill('=') << setw(40) << "" << endl;
    cout << setfill(' ') << setw(20) << "LISTA DE NOMES" << endl;
    cout << setfill('=') << setw(40) << "" << endl;
    cout << setfill(' ');
    
    for (size_t i = 0; i < nomes.size(); ++i) {
        cout << setw(3) << right << (i + 1) 
                  << ". " << setw(15) << left << nomes[i] << endl;
    }
    
    cout << setfill('=') << setw(40) << "" << endl;
    cout << setfill(' ') << "Total: " << nomes.size() << " nomes" << endl;
    cout << endl;
}

void salvarNomesEmArquivo(const vector<string>& nomes, 
                         const string& nomeArquivoSaida) {
    ofstream arquivo(nomeArquivoSaida);
    
    if (!arquivo.is_open()) {
        cerr << "Erro ao criar o arquivo de saída: " << nomeArquivoSaida << endl;
        return;
    }
    
    for (const string& nome : nomes) {
        arquivo << nome << endl;
    }
    
    arquivo.close();
    cout << "Dados salvos com sucesso no arquivo: " << nomeArquivoSaida << endl;
}
