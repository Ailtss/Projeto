#include "avenativo.h"

AveNativo::AveNativo()
{

}

AveNativo::AveNativo(string ibama, string uf_origem, string autorizacao,
int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, int tamanhoBico, int envergadura)
:Nativo(ibama, uf_origem, autorizacao), Ave(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, tamanhoBico, envergadura) {}


AveNativo::~AveNativo()
{

} 

