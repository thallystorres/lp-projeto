#include "Funcionario.hpp"

Funcionario::Funcionario(int id, const string &nome, const string &cpf, const string &cargo, double salario) : Pessoa(id, nome, cpf), cargo(cargo), salario(salario) {}

void Funcionario::mostrarDados() const
{
    cout << "[FUNCIONARIO] ";
    Pessoa::mostrarDados();
    cout << " | Cargo: " << this->cargo << "| Salario: "<< this->salario << endl;
}