#ifndef MAMIFERO_H
#define MAMIFERO_H
#include "animal.h"

/**@brief Classe Derivada da classe Animal*/
class Mamifero : public Animal
{

	protected:
		/**@brief Cor do pelo do mamífero*/
		string a_corPelo;

	public:
		Mamifero();
		Mamifero(int id, string classe, string nome, string nomeCient, char sexo, float tamanho, string dieta, Veterinario vet, Tratador trat, string batismo, string a_corPelo);
		~Mamifero();

		void impress();
		ostream& print(ostream &o);


};


#endif