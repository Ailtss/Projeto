#include "reptilExotico.h"

ReptilExotico::ReptilExotico()
{

}

ReptilExotico::ReptilExotico(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, bool venenoso, string tipoVeneno,
		string ibama, string paisOrigem)
:Exotico(ibama, paisOrigem), Reptil(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, venenoso, tipoVeneno) {}


ReptilExotico::~ReptilExotico()
{

} 