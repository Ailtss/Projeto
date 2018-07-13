#ifndef NATIVO_H
#define NATIVO_H
#include "animalSilvestre.h"

/**@brief Classe Nativo que herda da classe AnimalSilvestre*/
class Nativo : public AnimalSilvestre
{
protected:
	/**@brief UF de origem do animal*/
	string a_uf_origem; 
	/**@brief Autorização específica do animal*/
	string a_autorizacao; 

public:

	Nativo();
	Nativo(string ibama, string uf_origem, string autorizacao);
	~Nativo();

	


};
#endif