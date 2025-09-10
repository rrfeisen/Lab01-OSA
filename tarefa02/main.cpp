
#include "pessoa.hpp"

int main() {
    vector<Pessoa> todasPessoas;

    // Lê os 5 arquivos e junta tudo em um só vetor
    for (int i = 1; i <= 5; i++) {
        string nomeArquivo = "Nomes_Idades_" + to_string(i) + ".csv";
        vector<Pessoa> pessoas = lerCSV(nomeArquivo);
        todasPessoas.insert(todasPessoas.end(), pessoas.begin(), pessoas.end());
    }

    // Exibe os dados no console
    exibirPessoas(todasPessoas);

    // Salva em um novo arquivo consolidado
    salvarCSV(todasPessoas, "Nomes_Idades_Final.csv");

    return 0;
}
