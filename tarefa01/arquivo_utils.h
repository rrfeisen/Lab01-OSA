#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
/**
 * Função para ler nomes de um arquivo de texto
 * @param nomeArquivo Nome do arquivo a ser lido
 * @return Vetor contendo os nomes lidos do arquivo
 */
vector<string> lerNomesDoArquivo(const string& nomeArquivo);

/**
 * Função para exibir os nomes na tela de forma formatada
 * @param nomes Vetor contendo os nomes a serem exibidos
 */
void exibirNomes(const vector<string>& nomes);

/**
 * Função para salvar nomes em um arquivo de texto
 * @param nomes Vetor contendo os nomes a serem salvos
 * @param nomeArquivoSaida Nome do arquivo de saída
 */
void salvarNomesEmArquivo(const vector<string>& nomes, 
                         const string& nomeArquivoSaida);
