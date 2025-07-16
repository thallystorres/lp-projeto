#pragma once
#include <vector>

#include "Pessoa.hpp"
#include "Pedido.hpp"

using namespace std;

class Cliente : public Pessoa
{
private:
    string endereco;
    vector<Pedido> pedidos;

public:
    Cliente(int id, const string &nome, const string &cpf, const string& endereco);
    string getEndereco() const;
    void mostrarDados() const override;
    void adicionarPedido(const Pedido& pedido);
};