#include <iostream>
#include <fstream>
#include <map>
#include <memory>
#include <vector>
using namespace std;
#include "anfibioExotico.h"
#include "anfibioNativo.h"
#include "mamiferoExotico.h"
#include "mamiferoNativo.h"
#include "reptilExotico.h"
#include "reptilNativo.h"
#include "aveNativa.h"
#include "aveExotica.h"
#include "PetFera.h"

int main(int argc, char const *argv[])
{
	
	PetFera p;

	p.init();
	p.consultarAnimal();
	p.consultarPorFuncionario();
	p.endAnimais();

	return 0;
}