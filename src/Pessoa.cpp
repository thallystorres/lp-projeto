#include "Pessoa.hpp"

Pessoa::Pessoa(int id, const string &nome, const string &cpf) : id(id), nome(nome), cpf(cpf) {}

void Pessoa::setNome(const string &nome)
{
    this->nome = nome;
}

string Pessoa::getNome() const
{
    return this->nome;
}

string Pessoa::getCpf() const
{
    return this->cpf;
}

int Pessoa::getId() const
{
    return this->id;
}

void Pessoa::mostrarDados() const
{
    cout << "ID: " << this->id <<  " | CPF: " << this->cpf << " | nome: " << this->nome;
}