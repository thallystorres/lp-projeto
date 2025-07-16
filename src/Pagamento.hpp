#pragma once
#include <string>
#include <iostream>
using namespace std;

class Pagamento
{
private:
    int idPedido;
    string metodo;
    bool efetuado;
public:
    Pagamento(int idPedido);

    void processarPagamento(const string &metodoPagamento, double valor);
    void mostrarDados() const;
};