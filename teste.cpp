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

		string id;
		string tipo;
		string nome;
		string cpf;
		string idade;
		string tipo_sanguineo;
		string fatorRH;
		string especialidade;
		int _id;
		short _idade;
		const char *c_tipo_sanguineo;
		const char *c_fatorRH;

	while(!funcionarios.eof())
	{
		

		getline(funcionarios, id, ';');
		getline(funcionarios, tipo, ';');
		getline(funcionarios, nome, ';');
		getline(funcionarios, cpf, ';');
		getline(funcionarios, idade, ';');
		getline(funcionarios, tipo_sanguineo, ';');
		getline(funcionarios, fatorRH, ';');
		getline(funcionarios, especialidade, ';');
		_id = atoi(id.c_str());
		_idade = stoi(idade);
		c_tipo_sanguineo = tipo_sanguineo.c_str();
		c_fatorRH = fatorRH.c_str();
	}

	cout << _id << endl;
	cout << tipo << endl;
	cout << nome << endl;
	cout << cpf << endl;
	cout << _idade << endl;
	cout << c_tipo_sanguineo << endl;
	cout << c_fatorRH << endl;
	cout << especialidade << endl;

	/*if(tipo == "Tratador")
	{
		Tratador um(_id, nome, cpf, _idade, c_tipo_sanguineo, c_fatorRH, especialidade);
		um.impress();
	}
/*
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
		int _id = atoi(id.c_str());
		float _tamanho = atof(tamanho.c_str());
		const char *_sexo = sexo.c_str();
	}

*/








/*	cout << "Testando classe Funcionário: " << endl;
	cout << endl;
	cout << endl;

	Funcionario um(13, "Ailton Gabriel","070931384-54", 20, 0, '+');

	um.impress();

	cout << "Testando classe Veterinário: " << endl;
	cout << endl;
	cout << endl;

	Veterinario dois(13, "Figueira Dantas","070931384-54", 20, 0, '+', "Aves");

	Tratador tres(26, "Ramos da Silva", "070931384-54", 22, 1, '-', "Répteis");

	//dois.impress();

	//tres.impress();

	Ave teste(15, "Mammalia", "Leão", "Panthera Leo", 'M', 2, "Carne", dois, tres, "Simba", 10, 15);

	teste.impress();
*/
	
	animais.close();
	funcionarios.close();
	return 0;
}