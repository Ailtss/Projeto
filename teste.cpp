#include <iostream>
#include <fstream>
#include <map>
#include <memory>
using namespace std;
#include "anfibio.h"
#include "mamifero.h"
#include "reptil.h"
#include "aveNativa.h"
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
		Veterinario dois(13, "Figueira Dantas","070931384-54", 20, 0, '+', "Aves");

		Tratador tres(26, "Ramos da Silva", "070931384-54", 22, 1, '-', "Répteis");
		string id;
		string classe;
		string nome;
		string nomeCient;
		string sexo;
		string tamanho;
		string dieta;
		string vet;
		string trat;
		string batismo;
		string corPelo;
		getline(animais, id, ';');
		getline(animais, classe, ';');
		getline(animais, nome, ';');
		getline(animais, nomeCient, ';');
		getline(animais, sexo, ';');
		getline(animais, tamanho, ';');
		getline(animais, dieta, ';');
		getline(animais, vet, ';');
		getline(animais, trat, ';');
		getline(animais, batismo, ';');
		getline(animais, corPelo, ';');
		short _id = atoi(id.c_str());
		short _tamanho = atof(tamanho.c_str());
		const char *_sexo = sexo.c_str();
	}








/*	cout << "Testando classe Funcionário: " << endl;
	cout << endl;
	cout << endl;

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