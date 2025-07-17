#include "Cardapio.hpp"
#include "Utils.hpp"
void Cardapio::adicionarCategoria(const string &nome)
{
    this->categorias.emplace_back(this->proximaCategoriaId++, nome);
    cout << "Categoria '" << nome << "' adicionada com sucesso" << endl;
}

Categoria *Cardapio::buscarCategoriaPorId(int id)
{
    for (auto &categoria : this->categorias)
    {
        if (categoria.getId() == id)
        {
            return &categoria;
        }
    }
    throw runtime_error("Categoria não encontrada");
}

void Cardapio::listarCategorias() const
{
    listarItens("CATEGORIAS DISPONÍVEIS", this->categorias);
}

void Cardapio::adicionarProduto(const string &nome, double preco, int categoriaId)
{
    try
    {
        Categoria *categoriaDoProduto = this->buscarCategoriaPorId(categoriaId);
        this->produtos.emplace_back(this->proximoProdutoId++, nome, preco, categoriaDoProduto);
        cout << "Produto '" << nome << "' adicionado com sucesso!\n";
    }
    catch (const runtime_error &e)
    {
        throw runtime_error("Não foi possível adicionar o produto: " + string(e.what()));
    }
}

Produto *Cardapio::buscarProdutoPorId(int id)
{
    for (auto &produto : this->produtos)
    {
        if (produto.getId() == id)
        {
            return &produto;
        }
    }
    throw runtime_error("Produto não encontrado.");
}

void Cardapio::listarProdutos() const 
{
    listarItens("CARDÁPIO COMPLETO", this->produtos);
}

void Cardapio::removerProduto(int id)
{
    for(auto it = this->produtos.begin(); it != produtos.end(); ++it)
    {
        if(it->getId() == id)
        {
            this->produtos.erase(it);
            cout << "Produto removido com sucesso.\n";
            return;
        }
    }
    throw runtime_error("Produto a ser removido não encontrado");
}