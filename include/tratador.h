#ifndef TRATADOR_H
#define TRATADOR_H

#include "funcionario.h"


/**@brief Classe derivada Tratador que herda da classe Funcionario*/

class Tratador : public Funcionario
{

public:
	Tratador();
	Tratador(int id, string nome, string cpf, short idade, string tipo_sanguineo, char fatorRH, string especialidade);
	~Tratador();

	void impress();

	ostream& print(ostream& o);

};



#endif