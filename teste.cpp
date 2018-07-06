#include <iostream>
using namespace std;
#include "veterinario.h"
#include "tratador.h"
#include "animal.h"
#include "anfibio.h"
#include "mamifero.h"
#include "ave.h"


int main(int argc, char const *argv[])
{
	cout << "Testando classe Funcionário: " << endl;
	cout << endl;
	cout << endl;
/*
	Funcionario um(13, "Ailton Gabriel","070931384-54", 20, 0, '+');

	um.impress();
*/
	cout << "Testando classe Veterinário: " << endl;
	cout << endl;
	cout << endl;

	Veterinario dois(13, "Figueira Dantas","070931384-54", 20, 0, '+', "Aves");

	Tratador tres(26, "Ramos da Silva", "070931384-54", 22, 1, '-', "Répteis");

	//dois.impress();

	//tres.impress();

	Ave teste(15, "Mammalia", "Leão", "Panthera Leo", 'M', 2, "Carne", dois, tres, "Simba", 10, 15);

	teste.impress();

	

	return 0;
}