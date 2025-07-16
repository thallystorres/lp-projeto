#pragma once
#include "Pedido.hpp"

class Comanda{
private:
    vector<Pedido> todosOsPedidos;
    int proximoPedidoId = 1;
public:
    void registrarPedido(const Pedido& pedido);
    int getProximoId();
};