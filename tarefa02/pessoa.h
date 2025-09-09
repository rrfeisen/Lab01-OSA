#pragma once

#include <string>
using namespace std;

// Estrutura para representar uma pessoa com nome e idade
struct Pessoa {
    string nome;
    int idade;
    
    // Construtor padrão
    Pessoa() : nome(""), idade(0) {}
    
    // Construtor com parâmetros
    Pessoa(const string& n, int i) : nome(n), idade(i) {}
};
