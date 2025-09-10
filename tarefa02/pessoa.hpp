#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Pessoa {
    string nome;
    int idade;
};

vector<Pessoa> lerCSV(const string& nomeArquivo);
void exibirPessoas(const vector<Pessoa>& pessoas);
void salvarCSV(const vector<Pessoa>& pessoas, const string& nomeArquivo);
