#ifndef VETERINARIO_H
#define VETERINARIO_H
#include "funcionario.h"

/**@brief Classe Derivada Veterinário que herda da classe Funcionário*/

class Veterinario : public Funcionario 
{

public:
	Veterinario();
	Veterinario(int id, string nome, string cpf, short idade, string tipo_sanguineo, char fatorRH, string especialidade);
    ~Veterinario();
	void impress();

	ostream& print(ostream& o);


};


#endif