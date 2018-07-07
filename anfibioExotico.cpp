#include "anfibioExotico.h"

AnfibioExotico::AnfibioExotico()
{

}

AnfibioExotico::AnfibioExotico(string ibama, string paisOrigem,
int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, int totalMudas, string ultimaMuda)
:Exotico(ibama, paisOrigem), Anfibio(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, totalMudas, ultimaMuda) {}


AnfibioExotico::~AnfibioExotico()
{

}