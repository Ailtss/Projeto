#ifndef REPTIL_H
#define REPTIL_H
#include "animal.h"

class Reptil : public Animal
{
protected:
	bool a_venenoso;
	string a_tipoVeneno;

public:
	Reptil();
	Reptil(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, bool venenoso, string tipoVeneno);
	~Reptil();

	void impress();

	ostream& print(ostream &o);


};

#endif