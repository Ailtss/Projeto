#ifndef MAMIFERO_H
#define MAMIFERO_H
#include "animal.h"

class Mamifero : public Animal
{

	protected:
		string a_corPelo;

	public:
		Mamifero();
		Mamifero(int id, string classe, string nome, string nomeCient, char sexo, float tamanho, string dieta, Veterinario vet, Tratador trat, string batismo, string a_corPelo);
		~Mamifero();

		void impress();

};


#endif