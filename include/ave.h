#ifndef AVE_H
#define AVE_H
#include "animal.h"
/**@brief Classe Devidada da classe Animal*/
class Ave : public Animal
{

	protected:
		 /**@brief Tamnanho do bico da Ave*/
		int a_tamanhoBico;
		 /**@brief Envergadura da Ave*/
		int a_envergadura;

	public:
		Ave();
		Ave(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, int tamanhoBico, int envergadura);
		~Ave();

		void impress();

		ostream& print(ostream &o);

};

#endif