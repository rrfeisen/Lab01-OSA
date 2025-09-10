#include "pessoa.hpp"

vector<Pessoa> lerCSV(const string& nomeArquivo) {
    vector<Pessoa> pessoas;
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return pessoas;
    }

    string linha;
    getline(arquivo, linha); // descartar cabeçalho

    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string nome, idadeStr;

        getline(ss, nome, ',');
        getline(ss, idadeStr);

        if (!nome.empty() && !idadeStr.empty()) {
            Pessoa p;
            p.nome = nome;
            p.idade = stoi(idadeStr);
            pessoas.push_back(p);
        }
    }

    arquivo.close();
    return pessoas;
}

void exibirPessoas(const vector<Pessoa>& pessoas) {
    cout << left << setw(20) << "Nome" << setw(10) << "Idade" << endl;
    cout << string(30, '-') << endl;

    for (const auto& p : pessoas) {
        cout << left << setw(20) << p.nome << setw(10) << p.idade << endl;
    }
}

void salvarCSV(const vector<Pessoa>& pessoas, const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cerr << "Erro ao criar arquivo: " << nomeArquivo << endl;
        return;
    }

    arquivo << "name,age\n";
    for (const auto& p : pessoas) {
        arquivo << p.nome << "," << p.idade << "\n";
    }

    arquivo.close();
}
