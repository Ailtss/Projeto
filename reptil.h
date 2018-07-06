#ifndef REPTIL_H
#define REPTIL_H
#include "animal.h"

class Reptil : public Animal
{
protected:
	bool a_venenoso;
	string a_tipo_veneno;

public:
	Reptil();
	Reptil(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, bool veneno, string tipo_veneno);
	~Reptil();

	void impress();

}

#endif