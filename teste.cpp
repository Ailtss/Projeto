#include <iostream>
#include <fstream>
#include <map>
#include <memory>
using namespace std;
#include "anfibio.h"
#include "mamifero.h"
#include "reptil.h"
#include "avenativo.h"
#include "aveExotica.h"


int main(int argc, char const *argv[])
{

	map<int, unique_ptr<Animal>> listaAnimais;
	map<int, unique_ptr<Funcionario>> listaFuncionarios;
	ifstream animais, funcionarios;
	animais.open("animais.csv");
	funcionarios.open("funcionarios.csv");
	if(animais.bad() || funcionarios.bad())
	{
		cerr << "Os arquivos não abriram corretamente!" << endl;
	}

	while(!animais.eof())
	{
		string id,
		string classe;
		string nome;
		string nomeCient;
		string sexo;
		string tamanho;
		string dieta;
		Veterinario vet;
		Tratador trat;
		string batismo;
		string corPelo;
		getline(animais, id, ";");
	}








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

	
	animais.close();
	funcionarios.close();
	return 0;
}