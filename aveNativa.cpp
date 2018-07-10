#include "aveNativa.h"

AveNativa::AveNativa()
{

}

AveNativa::AveNativa(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, int tamanhoBico, int envergadura,
		string ibama, string uf_origem, string autorizacao)
:Nativo(ibama, uf_origem, autorizacao), Ave(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, tamanhoBico, envergadura) {}


AveNativa::~AveNativa()
{

}