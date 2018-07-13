#ifndef ANFIBIO_H
#define ANFIBIO_H
#include "animal.h"
/**@brief Classe Derivada da classe Animal*/
class Anfibio : public Animal
{

protected:
	/**@brief Total de mudas*/
	int a_totalMudas; 
	/**@brief Ultima muda*/
	string a_ultimaMuda; 

public:
	Anfibio();
	Anfibio(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, int totalMudas, string ultimaMuda);
	~Anfibio();

	void impress();

	ostream& print(ostream &o);

};


#endif