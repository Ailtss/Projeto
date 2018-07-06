#include "anfibio.h"


Anfibio::Anfibio()
{

}


Anfibio::Anfibio(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
	string dieta, Veterinario vet, Tratador trat, string batismo, int totalMudas, string ultimaMuda)
:Animal(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo)
{
	a_totalMudas = totalMudas;
	a_ultimaMuda = ultimaMuda;
}

Anfibio::~Anfibio()
{

}


void Anfibio::impress()
{
	cout << "Animal: " << a_nome << endl;
	cout << a_id << endl;
	cout << a_classe << endl;
	cout << a_nomeCient << endl;
	cout << a_sexo << endl;
	cout << a_tamanho << endl;
	cout << a_dieta << endl;
	cout << a_batismo << endl;

	cout << "Características Anfibio: " << endl;
	cout << "Total de mudas: " << a_totalMudas << endl;
	cout << "Última muda: " << a_ultimaMuda << endl;

	cout << endl;
	cout << endl;

	a_vet.impress();

	cout << endl;
	cout << endl;
	
	a_trat.impress();
}