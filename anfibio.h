#ifndef ANFIBIO_H
#define ANFIBIO_H
#include "animal.h"

class Anfibio : public Animal
{

protected:
	int a_totalmudas;
	int a_ultimamuda;

public:
	Anfibio();
	Anfibio(int id, string classe, string nome, string nomecient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, int totalmudas, int ultimamuda);
	~Anfibio();

	void impress();

};


#endif