#include "anfibio.h"


Anfibio::Anfibio()
{

}


Anfibio::Anfibio(int id, string classe, string nome, string nomecient, char sexo, float tamanho,
	string dieta, Veterinario vet, Tratador trat, string batismo, int totalmudas, int ultimamuda)
:Animal(id, classe, nome, nomecient, sexo, tamanho, dieta, vet, trat, batismo)
{
	a_totalmudas = totalmudas;
	a_ultimamuda = ultimamuda;
}

Anfibio::~Anfibio()
{

}


void Anfibio::impress()
{
	cout << "Animal: " << a_nome << endl;
	cout << a_id << endl;
	cout << a_classe << endl;
	cout << a_nomecient << endl;
	cout << a_sexo << endl;
	cout << a_tamanho << endl;
	cout << a_dieta << endl;
	cout << a_batismo << endl;

	cout << "Características Anfibio: " << endl;
	cout << "Total de mudas: " << a_totalmudas << endl;
	cout << "Última muda: " << a_ultimamuda << endl;

	cout << endl;
	cout << endl;

	a_vet.impress();

	cout << endl;
	cout << endl;
	
	a_trat.impress();
}