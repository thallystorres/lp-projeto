#include "Produto.hpp"

Produto::Produto(int id, const string &nome, double preco, Categoria *categoria) : id(id), nome(nome), preco(preco), categoria(categoria) {}

int Produto::getId()
{
    return this->id;
}

string Produto::getNome() const
{
    return this->nome;
}

double Produto::getPreco() const
{
    return this->preco;
}

Categoria *Produto::getCategoria() const
{
    return this->categoria;
}

void Produto::mostrarDados() const
{
    cout << "ID: " << this->id
         << " | Produto: " << this->nome
         << " | Categoria: " << (this-> categoria ? this->categoria->getNome() : "N/A")
         << " | Preço: R$" << preco << endl;
}