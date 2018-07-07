#ifndef PETFERA_H
#define PETFERA_H
#include <iostream>
#include <fstream>
#include <map>
#include <memory>
#include <vector>

using namespace std;

class PetFera
{
private:
	map<int, unique_ptr<Animal>> mapaAnimais;
	map<int, unique_ptr<Funcionario>> mapaFuncionarios;


};


#endif