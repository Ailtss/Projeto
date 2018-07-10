#include "anfibioNativo.h"

AnfibioNativo::AnfibioNativo()
{

}

AnfibioNativo::AnfibioNativo(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, int totalMudas, string ultimaMuda,
		string ibama, string uf_origem, string autorizacao)
:Nativo(ibama, uf_origem, autorizacao), Anfibio(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, totalMudas, ultimaMuda) {}


AnfibioNativo::~AnfibioNativo()
{

} 