#ifndef REPTILEXOTICO_H
#define REPTILEXOTICO_H

#include "reptil.h"
#include "exotico.h"

/**@brief Classe derivada da classe Exotico e Classe Reptil*/
class ReptilExotico : public Exotico, public Reptil
{

public:
	ReptilExotico();
	ReptilExotico(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, bool venenoso, string tipoVeneno,
		string ibama, string paisOrigem);
	~ReptilExotico();
	ostream& print(ostream &o);

};

#endif