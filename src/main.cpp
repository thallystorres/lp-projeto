#include "Menu.hpp"

int main() {
    Cardapio cardapio;
    GerenciadorClientes clientesManager;
    Comanda pedidosManager;

    int opcao;
    do {
        exibirMenuPrincipal();
        cin >> opcao;

        if (cin.fail()) {
            cout << "Erro: Entrada inválida. Por favor, digite um número.\n";
            cin.clear();
            limparBufferEntrada();
            opcao = -1;
            continue;
        }
        
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                logicaMenuCardapio(cardapio);
                break;
            case 2:
                logicaMenuClientes(clientesManager);
                break;
            case 3:
                logicaRealizarPedido(pedidosManager, cardapio, clientesManager);
                break;
            case 0:
                cout << "Encerrando o sistema. Até logo!\n";
                break;
            default:
                cout << "Opção inválida. Por favor, tente novamente.\n";
                break;
        }
    } while (opcao != 0);

    return 0;
}