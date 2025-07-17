#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>

#include "Cardapio.hpp"
#include "Comanda.hpp"
#include "GerenciadorClientes.hpp"

void exibirUtilsPrincipal() {
    cout << "\n========================================\n";
    cout << "   SISTEMA DE GESTÃO DE RESTAURANTE   \n";
    cout << "========================================\n";
    cout << "1. Gerenciar Cardápio\n";
    cout << "2. Gerenciar Clientes\n";
    cout << "3. Realizar um Pedido\n";
    cout << "0. Sair do Sistema\n";
    cout << "----------------------------------------\n";
    cout << "Escolha uma opção: ";
}

void exibirSubUtilsCardapio() {
    cout << "\n--- Gerenciar Cardápio ---\n";
    cout << "1. Adicionar Categoria\n";
    cout << "2. Adicionar Produto\n";
    cout << "3. Listar Categorias\n";
    cout << "4. Listar Todos os Produtos\n";
    cout << "5. Remover Produto\n";
    cout << "0. Voltar ao Menu Principal\n";
    cout << "Escolha uma opção: ";
}

void limparBufferEntrada() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void exibirSubUtilsClientes() {
    cout << "\n--- Gerenciar Clientes ---\n";
    cout << "1. Cadastrar Novo Cliente\n";
    cout << "2. Listar Todos os Clientes\n";
    cout << "0. Voltar ao Menu Principal\n";
    cout << "Escolha uma opção: ";
}

void logicaUtilsClientes(GerenciadorClientes& clientesManager) {
    int opcao;
    do {
        exibirSubUtilsClientes();
        cin >> opcao;

        if (cin.fail()) {
            cout << "Erro: Entrada inválida.\n";
            cin.clear();
            limparBufferEntrada();
            opcao = -1;
            continue;
        }
        limparBufferEntrada();

        switch (opcao) {
            case 1: {
                string nome, cpf, endereco;
                cout << "Digite o nome do cliente: ";
                getline(cin, nome);
                cout << "Digite o cpf do cliente: ";
                getline(cin, cpf);
                cout << "Digite o endereço do cliente: ";
                getline(cin, endereco);
                clientesManager.adicionarCliente(nome, cpf, endereco);
                break;
            }
            case 2:
                clientesManager.listarClientes();
                break;
            case 0:
                cout << "Voltando ao Menu principal...\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    } while (opcao != 0);
}

void logicaRealizarPedido(Comanda& pedidosManager, Cardapio& cardapio, GerenciadorClientes& clientesManager) {
    cout << "\n--- REALIZAR NOVO PEDIDO ---\n";

    clientesManager.listarClientes();
    cout << "Digite o ID do cliente que está fazendo o pedido: ";
    int clienteId;
    cin >> clienteId;
    limparBufferEntrada();

    Cliente* cliente;
    try {
        cliente = clientesManager.buscarClientePorId(clienteId);
    } catch (const runtime_error& e) {
        cerr << "ERRO: " << e.what() << ". Abortando criação de pedido.\n";
        return;
    }

    Pedido novoPedido(pedidosManager.getProximoId(), "16/07/2025");

    int produtoId;
    do {
        cardapio.listarProdutos();
        cout << "\nDigite o ID do produto para adicionar (ou 0 para finalizar): ";
        cin >> produtoId;
        limparBufferEntrada();

        if (produtoId != 0) {
            try {
                Produto* produto = cardapio.buscarProdutoPorId(produtoId);
                novoPedido.adicionarProduto(produto);
                cout << "'" << produto->getNome() << "' adicionado ao pedido.\n";
            } catch (const runtime_error& e) {
                cerr << "ERRO: " << e.what() << ". Tente novamente.\n";
            }
        }
    } while (produtoId != 0);
    
    if (novoPedido.calcularTotal() > 0) {
        cout << "\n--- Resumo do Pedido ---\n";
        novoPedido.mostrarDados();
        
        cout << "\n--- Processar Pagamento ---\n";
        cout << "1. Cartão de Crédito\n";
        cout << "2. Pix\n";
        cout << "3. Dinheiro\n";
        cout << "0. Cancelar Pagamento\n";
        cout << "Escolha o método de pagamento: ";
        int metodoOpcao;
        cin >> metodoOpcao;
        limparBufferEntrada();
        
        string metodoEscolhido;
        bool pagamentoCancelado = false;

        switch(metodoOpcao) {
            case 1: metodoEscolhido = "Cartão de Crédito"; break;
            case 2: metodoEscolhido = "Pix"; break;
            case 3: metodoEscolhido = "Dinheiro"; break;
            case 0:
                cout << "Pagamento cancelado pelo usuário.\n";
                pagamentoCancelado = true;
                break;
            default:
                cout << "Opção inválida. Pagamento cancelado.\n";
                pagamentoCancelado = true;
                break;
        }

        if (!pagamentoCancelado) {
            Pagamento& pagamentoDoPedido = novoPedido.getPagamento();
            pagamentoDoPedido.processarPagamento(metodoEscolhido, novoPedido.calcularTotal());
            
            novoPedido.marcarComoPago();
            
            cout << "\n--- Pedido Finalizado ---\n";
            novoPedido.mostrarDados();
            
            cliente->adicionarPedido(novoPedido);
            pedidosManager.registrarPedido(novoPedido);
        } else {
             cout << "O pedido continua aguardando pagamento.\n";
        }

    } else {
        cout << "\nNenhum produto foi adicionado. Pedido cancelado.\n";
    }
}

void logicaUtilsCardapio(Cardapio& cardapio) {
    int opcao;
    do {
        exibirSubUtilsCardapio();
        cin >> opcao;

        if (cin.fail()) {
            cout << "Erro: Entrada inválida. Por favor, digite um número.\n";
            cin.clear();
            limparBufferEntrada();
            opcao = -1;
            continue;
        }
        
        limparBufferEntrada();

        try {
            switch (opcao) {
                case 1: {
                    string nomeCat;
                    cout << "Digite o nome da nova categoria: ";
                    getline(cin, nomeCat);
                    cardapio.adicionarCategoria(nomeCat);
                    break;
                }
                case 2: {
                    string nomeProd;
                    double preco;
                    int catId;
                    cout << "Digite o nome do novo produto: ";
                    getline(cin, nomeProd);
                    cout << "Digite o preço do produto: ";
                    cin >> preco;
                    cardapio.listarCategorias();
                    cout << "Digite o ID da categoria do produto: ";
                    cin >> catId;
                    limparBufferEntrada();
                    cardapio.adicionarProduto(nomeProd, preco, catId);
                    break;
                }
                case 3:
                    cardapio.listarCategorias();
                    break;
                case 4:
                    cardapio.listarProdutos();
                    break;
                case 5: {
                    int prodId;
                    cardapio.listarProdutos();
                    cout << "Digite o ID do produto a ser removido: ";
                    cin >> prodId;
                    limparBufferEntrada();
                    cardapio.removerProduto(prodId);
                    break;
                }
                case 0:
                    cout << "Voltando ao Menu principal...\n";
                    break;
                default:
                    cout << "Opção inválida. Tente novamente.\n";
                    break;
            }
        } catch (const runtime_error& e) {
            cerr << "ERRO: " << e.what() << endl;
        }

    } while (opcao != 0);
}