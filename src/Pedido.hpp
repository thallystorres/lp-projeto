#pragma once
#include <vector>
#include "Produto.hpp"
#include "Pagamento.hpp"
using namespace std;

enum StatusPedido { AGUARDANDO_PAGAMENTO, PAGO, CANCELADO};

class Pedido
{
private:
    int id;
    string data;
    vector<Produto *> produtos;
    Pagamento pagamento;
    StatusPedido status;

public:
    Pedido(int id, const string &data);

    Pagamento& getPagamento();
    
    void marcarComoPago();
    void adicionarProduto(Produto *produto);
    double calcularTotal() const;
    void mostrarDados() const;
};