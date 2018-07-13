#ifndef REPTIL_H
#define REPTIL_H
#include "animal.h"

/**@brief Classe Reptil derivada da classe Animal*/
class Reptil : public Animal
{
protected:
	/**@brief Saber se o Reptil é venenoso ou não*/
	bool a_venenoso; 
	/**@brief Tipo de Veneno*/
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