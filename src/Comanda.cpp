#include "Comanda.hpp"

void Comanda::registrarPedido(const Pedido& pedido)
{
    this->todosOsPedidos.push_back(pedido);
    cout << "\nPedido registrado com sucesso no sistema!\n";
}

int Comanda::getProximoId()
{
    return this->proximoPedidoId++;
}