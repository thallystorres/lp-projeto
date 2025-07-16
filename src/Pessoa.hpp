#pragma once
#include <string>
#include <iostream>

using namespace std;

class Pessoa
{
protected:
    int id;
    string nome;
    string cpf;

public:
    Pessoa(int id, const string &nome, const string &cpf);
    virtual void mostrarDados() const;
    virtual ~Pessoa() {}

    void setNome(const string& nome);
    int getId() const;
    string getNome() const;
    string getCpf() const;
};
