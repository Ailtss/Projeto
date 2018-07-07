#include "anfibioNativo.h"

AnfibioNativo::AnfibioNativo()
{

}

AnfibioNativo::AnfibioNativo(string ibama, string uf_origem, string autorizacao,
int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, int totalMudas, string ultimaMuda)
:Nativo(ibama, uf_origem, autorizacao), Anfibio(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, totalMudas, ultimaMuda) {}


AnfibioNativo::~AnfibioNativo()
{

} 