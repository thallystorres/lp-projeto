#include "GerenciadorClientes.hpp"
#include "Utils.hpp"
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
    listarItens("LISTA DE CLIENTES", this->clientes);
}