#ifndef NATIVO_H
#define NATIVO_H
#include "animalSilvestre.h"

class Nativo : public AnimalSilvestre
{
protected:
	string a_uf_origem;
	string a_autorizacao;

public:

	Nativo();
	Nativo(string ibama, string uf_origem, string autorizacao);
	~Nativo();

	


};
#endif