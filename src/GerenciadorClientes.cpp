#include "GerenciadorClientes.hpp"

void GerenciadorClientes::adicionarCliente(const string& nome, const string& cpf, const string& endereco)
{
    this->clientes.emplace_back(this->proximoClienteId++, nome, cpf, endereco);
    cout << "Cliente '" << nome << "' cadastrado com sucesso!\n";
}

Cliente* GerenciadorClientes::buscarClientePorId(int id)
{
    for(auto& cliente : this->clientes)
    {
        if(cliente.getId() == id)
        {
            return &cliente;
        }
    }
    throw runtime_error("Cliente não encontrado.");
}

void GerenciadorClientes::listarClientes() const
{
    cout << "\n--- LISTA DE CLIENTES ---\n";
    if(this->clientes.empty())
    {
        cout << "Nenhum cliente cadastrado.\n";
    }
    for(const auto& cliente : this->clientes)
    {
        cliente.mostrarDados();
    }
    cout << "-------------------\n";
}