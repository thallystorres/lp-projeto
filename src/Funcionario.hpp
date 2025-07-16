#pragma once
#include "Pessoa.hpp"

using namespace std;

class Funcionario : public Pessoa
{
private:
    string cargo;
    double salario;
public:
    Funcionario(int id, const string& nome,const  string& cpf,const  string& cargo, double salario);
    void mostrarDados() const override;
};