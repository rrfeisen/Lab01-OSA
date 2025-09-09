#pragma once

#include <vector>
#include <string>
#include "Pessoa.h"
using namespace std;

// Função para ler o arquivo CSV e retornar vetor de pessoas
vector<Pessoa> lerArquivoCSV(const string& nomeArquivo);

// Função para exibir os dados das pessoas de forma formatada
void exibirPessoas(const vector<Pessoa>& pessoas);

// Função para salvar os dados em um arquivo de saída no formato CSV
void salvarArquivoCSV(const vector<Pessoa>& pessoas, const string& nomeArquivo);

// Função auxiliar para fazer trim (remover espaços) de uma string
string trim(const string& str);
