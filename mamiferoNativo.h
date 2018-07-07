#ifndef MAMIFERONATIVO_H
#define MAMIFERONATIVO_H

#include "mamifero.h"
#include "nativo.h"

class MamiferoNativo : public Nativo, public Mamifero
{

public:
	MamiferoNativo();
	MamiferoNativo(string ibama, string uf_origem, string autorizacao,
		int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, string corPelo);
	~MamiferoNativo();

};

#endif