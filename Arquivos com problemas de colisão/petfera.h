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
#include "tratador.h"
#include "veterinario.h"
#include "funcionario.h"

using namespace std;

class PetFera
{
private:
	map<int, shared_ptr<Animal>> mapaAnimais;
	map<int, shared_ptr<Funcionario>> mapaFuncionarios;

public:
	PetFera();
	//void CadastrarTrat();
	void menu();
	void consultarAnimal(string key);
	void RemoveFuncionario(int id);
	void RemoveAnimal(int id);

	void cadastrartTrat(Tratador t);
	void cadastrarVet(Veterinario v);



};


#endif