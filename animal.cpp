#include "animal.h"

//Implementar Construtores, Destrutores e métodos da classes

Animal::Animal()
{

}

Animal::Animal(int id, string classe, string nome, string nomeCient, char sexo, float tamanho, string dieta, Veterinario vet, Tratador trat, string batismo)
{
	a_id = id;
	a_classe = classe;
	a_nome = nome;
	a_nomeCient = nomeCient;
	a_sexo = sexo;
	a_tamanho = tamanho;
	a_dieta = dieta;
	a_vet = vet;
	a_trat = trat;
	a_batismo = batismo;


}

Animal::~Animal()
{

}



//setters

void Animal::setAnId(int id)
{
	a_id = id;
}

void Animal::setAnClasse(string classe)
{
	a_classe = classe;
}

void Animal::setAnNome(string nome)
{
	a_nome = nome;
}

void Animal::setAnNomeCient(string nomeCient)
{
	a_nomeCient = nomeCient;
}

void Animal::setAnSexo(char sexo)
{
	a_sexo = sexo;
}
void Animal::setAnTamanho(float tamanho)
{
	a_tamanho = tamanho;
}
void Animal::setAnDieta(string dieta)
{
	a_dieta = dieta;
}
void Animal::setAnVet(Veterinario vet)
{
	a_vet = vet;
}
void Animal::setAnTrat(Tratador trat)
{
	a_trat = trat;
}
void Animal::setAnBatismo(string batismo)
{
	a_batismo = batismo;
}


//getters

int Animal::getAnId()
{
	return a_id;
}

string Animal::getAnClasse()
{
	return a_classe;
}

string Animal::getAnNome()
{
	return a_nome;
}

string Animal::getAnNomeCient()
{
	return a_nomeCient;
}

char Animal::getAnSexo()
{
	return a_sexo;
}

float Animal::getAnTamanho()
{
	return a_tamanho;
}

string Animal::getAnDieta()
{
	return a_dieta;
}

Veterinario Animal::getAnVet()
{
	return a_vet;
}

Tratador Animal::getAnTrat()
{
	return a_trat;
}

string Animal::getAnBatismo()
{
	return a_batismo;
}

void Animal::impress()
{
	cout << "Animal: " << a_nome << endl;
	cout << a_id << endl;
	cout << a_classe << endl;
	cout << a_nomeCient << endl;
	cout << a_sexo << endl;
	cout << a_tamanho << endl;
	cout << a_dieta << endl;
	cout << a_batismo << endl;

	cout << endl;
	cout << endl;

	a_vet.impress();

	cout << endl;
	cout << endl;
	
	a_trat.impress();

}