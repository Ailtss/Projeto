#include "reptil.h"


Reptil::Reptil()
{

}


Reptil::Reptil(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, bool venenoso, string tipoVeneno)
:Animal(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo)
{
	a_venenoso = venenoso;
	a_tipoVeneno = tipoVeneno;
}

Reptil::~Reptil()
{

}

void Reptil::impress()
{
	cout << "Animal: " << a_nome << endl;
	cout << a_id << endl;
	cout << a_classe << endl;
	cout << a_nomeCient << endl;
	cout << a_sexo << endl;
	cout << a_tamanho << endl;
	cout << a_dieta << endl;
	cout << a_batismo << endl;

	cout << "Caracterísicas Reptil: " << endl;
	cout << "Venenoso? " << a_venenoso << endl;
	cout << "Tipo do Veneno: " << a_tipoVeneno << endl;

	cout << endl;
	cout << endl;

	a_vet.impress();

	cout << endl;
	cout << endl;

	a_trat.impress();

}