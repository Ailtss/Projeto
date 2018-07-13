#ifndef AVENATIVA_H
#define AVENATIVA_H

#include "ave.h"
#include "nativo.h"
/**@brief Classe Derivada da classe Ave e da classe Nativo*/
class AveNativa : public Nativo, public Ave
{
public:
	AveNativa();
	AveNativa(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, int tamanhoBico, int envergadura,
		string ibama, string uf_origem, string autorizacao);
	~AveNativa();
	ostream& print(ostream &o);
};

#endif