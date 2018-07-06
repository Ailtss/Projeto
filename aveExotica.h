#ifndef AVEEXOTICA_H
#define AVEEXOTICA_H

#include "exotico.h"
#include "ave.h"

class AveExotica : public Ave, public Exotico
{
	public:
		AveExotica();
		AveExotica(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
	string dieta, Veterinario vet, Tratador trat, string batismo, int tamanhoBico, int envergadura, string ibama, string paisOrigem);
		~AveExotica();
};

#endif