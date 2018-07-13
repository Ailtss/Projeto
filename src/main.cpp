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

/**
 *@file main.cpp
 *@brief Programa PetFera
 *@author Ailton Gabriel Figueira Dantas Ramos da Silva
 *@author Felipe Douglas Cavalcante Marinho de Vasconcelos
 *@since 01/07/2018
 *@date 12/07/2018
*/

int main(int argc, char const *argv[])
{
	
	PetFera p;

	p.menu();

	return 0;
}