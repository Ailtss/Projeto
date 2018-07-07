#ifndef ANFIBIOEXOTICO_H
#define ANFIBIOEXOTICO_H

#include "anfibio.h"
#include "exotico.h"

class AnfibioExotico : public Exotico, public Anfibio
{

public:
	AnfibioExotico();
	AnfibioExotico(string ibama, string paisOrigem,
		int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, int totalMudas, string ultimaMuda);
	~AnfibioExotico();

};

#endif