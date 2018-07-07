#ifndef AVENATIVA_H
#define AVENATIVA_H

#include "ave.h"
#include "nativo.h"

class AveNativa : public Nativo, public Ave
{
	AveNativa();
	AveNativa(string ibama, string uf_origem, string autorizacao,
		int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, int tamanhoBico, int envergadura);
	~AveNativa();
};

#endif