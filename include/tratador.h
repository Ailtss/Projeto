#ifndef TRATADOR_H
#define TRATADOR_H

#include "funcionario.h"




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