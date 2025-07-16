#pragma once
#include <stdexcept>
#include "Cliente.hpp"

class GerenciadorClientes{
private:
    vector<Cliente> clientes;
    int proximoClienteId = 1;

public:
    void adicionarCliente(const string& nome, const string& cpf, const string& endereco);
    Cliente* buscarClientePorId(int id);
    void listarClientes() const;
};