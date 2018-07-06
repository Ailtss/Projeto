#include "ave.h"

Ave::Ave()
{

}

Ave::Ave(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
	string dieta, Veterinario vet, Tratador trat, string batismo, int tamanhoBico, int envergadura)
:Animal(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo)
{
	a_tamanhoBico = tamanhoBico;
	a_envergadura = envergadura;
}

Ave::~Ave()
{

}

void Ave::impress()
{
	cout << "Animal: " << a_nome << endl;
	cout << a_id << endl;
	cout << a_classe << endl;
	cout << a_nomeCient << endl;
	cout << a_sexo << endl;
	cout << a_tamanho << endl;
	cout << a_dieta << endl;
	cout << a_batismo << endl;

	cout << "Características Ave: " << endl;
	cout << "Tamanho do bico: " << a_tamanhoBico << endl;
	cout << "Envergadura: " << a_envergadura << endl;

	cout << endl;
	cout << endl;

	a_vet.impress();

	cout << endl;
	cout << endl;
	
	a_trat.impress();
}