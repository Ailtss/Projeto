#ifndef PETFERA_H
#define PETFERA_H
#include <memory>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "animalSilvestre.h"
#include "mamiferoNativo.h"
#include "mamiferoExotico.h"
#include "aveExotica.h"
#include "aveNativa.h"
#include "anfibioExotico.h"
#include "anfibioNativo.h"
#include "reptilExotico.h"
#include "reptilNativo.h"
using namespace std;

#include "animal.h"
#include "funcionario.h"

class PetFera
{
protected:
	map<int, shared_ptr<Animal>> mapaAnimais;
	map<int, shared_ptr<Veterinario>> mapaVeterinarios;
	map<int, shared_ptr<Tratador>> mapaTratadores;
public:
	PetFera();
	~PetFera();
	void clearScreen();
	void init();
	void cadastrarAnimalNativo();
	void cadastrarAnimalExotico();
	void cadastrarVeterinario();
	void cadastrarTratador();
	void consultarAnimal();
	void consultarPorFuncionario();
	bool removerAnimal();
	bool removerFuncionario();
	void endAnimais();
	void endFuncionarios();
	void listarAnimais();
	void listarFuncionarios();
	void menu();
};

#endif