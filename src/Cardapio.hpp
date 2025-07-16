#pragma once
#include <vector>
#include <stdexcept>
#include "Produto.hpp"
#include "Categoria.hpp"

using namespace std;

class Cardapio
{
private:
    vector<Categoria> categorias;
    vector<Produto> produtos;
    int proximaCategoriaId = 1;
    int proximoProdutoId = 1;
public:
    Cardapio() = default;

    void adicionarCategoria(const string& nome);
    Categoria* buscarCategoriaPorId(int id);
    void listarCategorias() const;

    void adicionarProduto(const string &nome, double preco, int categoriaId);
    Produto* buscarProdutoPorId(int id);
    void listarProdutos() const;
    void removerProduto(int id);
};