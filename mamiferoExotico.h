#ifndef MAMIFEROEXOTICO_H
#define MAMIFEROEXOTICO_H

#include "mamifero.h"
#include "exotico.h"

class MamiferoExotico : public Exotico, public Mamifero
{

public:
	MamiferoExotico();
	MamiferoExotico(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, string corPelo, string ibama, string paisOrigem);
	~MamiferoExotico();

};

#endif