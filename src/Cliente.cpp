#include "Cliente.hpp"

Cliente::Cliente(int id, const string &nome, const string &cpf, const string &endereco) : Pessoa(id, nome, cpf), endereco(endereco) {}

void Cliente::mostrarDados() const
{
    cout << "[CLIENTE] ";
    Pessoa::mostrarDados();
    cout << " | Endereço: " << this->endereco << endl;
}

void Cliente::adicionarPedido(const Pedido &pedido)
{
    pedidos.push_back(pedido);
}