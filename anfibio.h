#ifndef ANFIBIO_H
#define ANFIBIO_H
#include "animal.h"

class Anfibio : public Animal
{

protected:
	int a_totalMudas;
	string a_ultimaMuda;

public:
	Anfibio();
	Anfibio(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, int totalMudas, string ultimaMuda);
	~Anfibio();

	void impress();

};


#endif