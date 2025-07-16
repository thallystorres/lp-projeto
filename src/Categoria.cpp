#include "Categoria.hpp"

Categoria::Categoria(int id = 0, const string& nome = "") : id(id), nome(nome) {}

int Categoria::getId() const
{
    return this->id;
}

string Categoria::getNome() const
{
    return this->nome;
}

void Categoria::mostrarDados() const {
    cout << "Categoria ID: " << this->id << " | Nome: " << nome << endl;
}