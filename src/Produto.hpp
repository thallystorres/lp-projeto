#pragma once
#include "Categoria.hpp"
using namespace std;

class Produto
{
private:
    int id;
    string nome;
    double preco;
    Categoria *categoria;

public:
    Produto(int id, const string &nome, double preco, Categoria *categoria);
    int getId();
    string getNome() const;
    double getPreco() const;
    Categoria* getCategoria() const;
    
    void mostrarDados() const;
};