#include "ArquivoUtils.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

// Função auxiliar para remover espaços em branco no início e fim da string
string trim(const string& str) {
    size_t inicio = str.find_first_not_of(" \t\r\n");
    if (inicio == string::npos) {
        return ""; // String vazia ou só espaços
    }
    
    size_t fim = str.find_last_not_of(" \t\r\n");
    return str.substr(inicio, fim - inicio + 1);
}

// Função para ler arquivo CSV e popular vetor de pessoas
vector<Pessoa> lerArquivoCSV(const string& nomeArquivo) {
    vector<Pessoa> pessoas;
    ifstream arquivo(nomeArquivo);
    
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return pessoas; // Retorna vetor vazio
    }
    
    string linha;
    bool primeiraLinha = true;
    
    // Lê linha por linha do arquivo
    while (getline(arquivo, linha)) {
        // Pula o cabeçalho (primeira linha)
        if (primeiraLinha) {
            primeiraLinha = false;
            continue;
        }
        
        // Processa a linha CSV
        stringstream ss(linha);
        string nome, idadeStr;
        
        // Separa por vírgula
        if (getline(ss, nome, ',') && getline(ss, idadeStr)) {
            // Remove espaços em branco
            nome = trim(nome);
            idadeStr = trim(idadeStr);
            
            try {
                int idade = stoi(idadeStr);
                pessoas.emplace_back(nome, idade);
            } catch (const exception& e) {
                cerr << "Erro ao converter idade: " << idadeStr << endl;
            }
        }
    }
    
    arquivo.close();
    cout << "Lidos " << pessoas.size() << " registros do arquivo " << nomeArquivo << endl;
    return pessoas;
}

// Função para exibir pessoas de forma formatada
void exibirPessoas(const vector<Pessoa>& pessoas) {
    cout << "\n" << string(50, '=') << endl;
    cout << setw(25) << left << "Nome" 
              << setw(10) << "Idade" << endl;
    cout << string(50, '-') << endl;
    
    for (const auto& pessoa : pessoas) {
        cout << setw(25) << left << pessoa.nome 
                  << setw(10) << pessoa.idade << endl;
    }
    
    cout << string(50, '=') << endl;
    cout << "Total de pessoas: " << pessoas.size() << endl;
}

// Função para salvar dados em arquivo CSV
void salvarArquivoCSV(const vector<Pessoa>& pessoas, const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo);
    
    if (!arquivo.is_open()) {
        cerr << "Erro ao criar o arquivo: " << nomeArquivo << endl;
        return;
    }
    
    // Escreve o cabeçalho
    arquivo << "name,age" << endl;
    
    // Escreve os dados das pessoas
    for (const auto& pessoa : pessoas) {
        arquivo << pessoa.nome << "," << pessoa.idade << endl;
    }
    
    arquivo.close();
    cout << "Dados salvos em: " << nomeArquivo << endl;
}
