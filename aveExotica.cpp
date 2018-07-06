#include "aveExotica.h"

AveExotica::AveExotica()
{

}

AveExotica::AveExotica(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
	string dieta, Veterinario vet, Tratador trat, string batismo, int tamanhoBico, int envergadura, string ibama, string paisOrigem)
:Ave(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, tamanhoBico, envergadura), Exotico(ibama, paisOrigem)
{

}

AveExotica::~AveExotica()
{

}