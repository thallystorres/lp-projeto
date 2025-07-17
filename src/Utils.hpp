#pragma once

#include "Cardapio.hpp"
#include "GerenciadorClientes.hpp"
#include "Comanda.hpp"

void exibirUtilsPrincipal();
void logicaUtilsCardapio(Cardapio& cardapio);
void logicaUtilsClientes(GerenciadorClientes& clientesManager);
void logicaRealizarPedido(Comanda& pedidosManager, Cardapio& cardapio, GerenciadorClientes& clientesManager);
void limparBufferEntrada();

template <typename T>
void listarItens(const string& titulo, const vector<T>& itens) {
    cout << "\n--- " << titulo << " ---\n";
    if (itens.empty()) {
        cout << "Nenhum item cadastrado.\n";
        return;
    }
    for (const auto& item : itens) {
        item.mostrarDados();
    }
    cout << "-----------------------------------\n";
}
