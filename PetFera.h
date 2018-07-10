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
	map<int, shared_ptr<Funcionario>> mapaFuncionarios;
public:
	PetFera();
	void init();

};

#endif