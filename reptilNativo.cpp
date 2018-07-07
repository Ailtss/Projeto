#include "reptilNativo.h"

ReptilNativo::ReptilNativo()
{

}

ReptilNativo::ReptilNativo(string ibama, string uf_origem, string autorizacao,
int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, bool venenoso, string tipoVeneno)
:Nativo(ibama, uf_origem, autorizacao), Reptil(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, venenoso, tipoVeneno) {}


ReptilNativo::~ReptilNativo()
{

} 