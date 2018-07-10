#include "anfibioExotico.h"

AnfibioExotico::AnfibioExotico()
{

}

AnfibioExotico::AnfibioExotico(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, int totalMudas, string ultimaMuda,
		string ibama, string paisOrigem)
:Exotico(ibama, paisOrigem), Anfibio(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, totalMudas, ultimaMuda) {}


AnfibioExotico::~AnfibioExotico()
{

}