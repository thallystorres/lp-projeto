#include "Pedido.hpp"

Pedido::Pedido(int id, const string &data) : id(id), data(data), pagamento(id), status(AGUARDANDO_PAGAMENTO) {}


Pagamento &Pedido::getPagamento()
{
    return this->pagamento;
}

void Pedido::marcarComoPago()
{
    this->status = PAGO;
}

void Pedido::adicionarProduto(Produto *produto)
{
    this->produtos.push_back(produto);
}

double Pedido::calcularTotal() const
{
    double total = 0.0;
    for (const auto *produto : this->produtos)
    {
        total += produto->getPreco();
    }
    return total;
}

void Pedido::mostrarDados() const
{
    cout << "--- Pedido ID: " << this->id << " | Data: " << this->data << "---" << endl;
    cout << "Produtos:" << endl;
    for (const auto *produto : this->produtos)
    {
        cout << " - " << produto->getNome() << "(R$ " << produto->getPreco() << ")";
    }
    cout << "Total: R$ " << this->calcularTotal() << endl;
    cout << "Status: ";
    switch(status) {
        case AGUARDANDO_PAGAMENTO: cout << "Aguardando Pagamento"; break;
        case PAGO: cout << "Pago"; break;
        case CANCELADO: cout << "Cancelado"; break;
    }
    cout << endl;
}