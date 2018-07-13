#ifndef MAMIFERONATIVO_H
#define MAMIFERONATIVO_H

#include "mamifero.h"
#include "nativo.h"

/**@brief Classe Derivada que herda da classe Naitvo e da classe Mamifero*/
class MamiferoNativo : public Nativo, public Mamifero
{

public:
	MamiferoNativo();
	MamiferoNativo(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, string corPelo,
		string ibama, string uf_origem, string autorizacao);
	~MamiferoNativo();
	ostream& print(ostream &o);

};

#endif