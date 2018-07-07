#ifndef PETFERA_H
#define PETFERA_H
#include <iostream>
#include <fstream>
#include <map>
#include <memory>
#include <vector>
#include "anfibio.h"
#include "mamifero.h"
#include "reptil.h"
#include "aveNativa.h"
#include "aveExotica.h"

using namespace std;

class PetFera
{
private:
	map<int, unique_ptr<Animal>> mapaAnimais;
	map<int, unique_ptr<Funcionario>> mapaFuncionarios;

public:
	PetFera();
	void CadastrarTrat();



};


#endif