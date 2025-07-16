#pragma once
#include <string>
#include <iostream>

using namespace std;

class Categoria{
private:
    int id;
    string nome;
public:
    Categoria(int id, const string& nome);
    int getId() const;
    string getNome() const;

    void mostrarDados() const;
};