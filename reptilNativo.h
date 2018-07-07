#ifndef REPTILNATIVO_H
#define REPTILNATIVO_H

#include "reptil.h"
#include "nativo.h"

class ReptilNativo : public Nativo, public Reptil
{

public:
	ReptilNativo();
	ReptilNativo(string ibama, string uf_origem, string autorizacao,
		int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, bool venenoso, string tipoVeneno);
	~ReptilNativo();

};

#endif