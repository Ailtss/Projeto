#include "reptil.h"


Reptil::Reptil()
{

}


Reptil::Reptil(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, bool veneno, string tipo_veneno)
:Animal(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo)
{
	a_veneno = veneno;
	a_tipo_veneno = tipo_veneno;
}

Reptil::~Reptil()
{

}

void Reptil::impress()
{
	cout << "Animal: " << a_nome << endl;
	cout << a_id << endl;
	cout << a_classe << endl;
	cout << a_nomecient << endl;
	cout << a_sexo << endl;
	cout << a_tamanho << endl;
	cout << a_dieta << endl;
	cout << a_batismo << endl;

	cout << "Caracterísicas Reptil: " << endl;
	cout << "Venenoso? " << a_veneno << endl;
	cout << "Tipo do Veneno: " << a_tipo_veneno << endl;

	cout << endl;
	cout << endl;

	a_vet.impress();

	cout << endl;
	cout << endl;

	a_trat.impress();

}