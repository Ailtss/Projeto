#include "mamiferoNativo.h"

MamiferoNativo::MamiferoNativo()
{

}

MamiferoNativo::MamiferoNativo(string ibama, string uf_origem, string autorizacao,
int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, string corPelo)
:Nativo(ibama, uf_origem, autorizacao), Mamifero(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, corPelo) {}


MamiferoNativo::~MamiferoNativo()
{

} 