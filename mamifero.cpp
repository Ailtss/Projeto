#include "mamifero.h"

Mamifero::Mamifero()
{

}

Mamifero::Mamifero(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
	string dieta, Veterinario vet, Tratador trat, string batismo, string corPelo)
:Animal(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo)
{
	a_corPelo = corPelo;
}

Mamifero::~Mamifero()
{

}

void Mamifero::impress()
{
	cout << "Animal: " << a_nome << endl;
	cout << a_id << endl;
	cout << a_classe << endl;
	cout << a_nomeCient << endl;
	cout << a_sexo << endl;
	cout << a_tamanho << endl;
	cout << a_dieta << endl;
	cout << a_batismo << endl;

	cout << "Características Mamifero: " << endl;
	cout << "Cor do pelo: " << a_corPelo << endl;

	cout << endl;
	cout << endl;

	a_vet.impress();

	cout << endl;
	cout << endl;
	
	a_trat.impress();
}