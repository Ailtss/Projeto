#include "mamiferoExotico.h"

MamiferoExotico::MamiferoExotico()
{

}

MamiferoExotico::MamiferoExotico(string ibama, string paisOrigem,
int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, string corPelo)
:Exotico(ibama, paisOrigem), Mamifero(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, corPelo) {}


MamiferoExotico::~MamiferoExotico()
{

} 