#pragma once

// Precisamos incluir os headers das classes que as funções usam como parâmetros
#include "Cardapio.hpp"
#include "GerenciadorClientes.hpp"
#include "Comanda.hpp" // ou "GerenciadorPedidos.hpp", o nome que você estiver usando

// Declaração (protótipo) de todas as funções de interface
void exibirMenuPrincipal();
void logicaMenuCardapio(Cardapio& cardapio);
void logicaMenuClientes(GerenciadorClientes& clientesManager);
void logicaRealizarPedido(Comanda& pedidosManager, Cardapio& cardapio, GerenciadorClientes& clientesManager);
void limparBufferEntrada();