#include "Pagamento.hpp"

Pagamento::Pagamento(int idPedido = 0) : idPedido(idPedido), efetuado(false) {}

void Pagamento::processarPagamento(const string &metodoPagamento, double valor)
{
    this->metodo = metodoPagamento;
    this->efetuado = true;
    cout << "Pagamento de R$" << valor << " processado com " << metodo << "." << endl;
}

void Pagamento::mostrarDados() const
{
    cout << "Detalhes do Pagamento (Pedido " << this->idPedido << "): " << endl;
    if (this->efetuado)
    {
        cout << "Método: " << metodo << " | Status: Efetuado" << endl;
    }
    else
    {
        cout << "Status: Pagamento não realizado." << endl;
    }
}
