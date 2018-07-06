#ifndef VETERINARIO_H
#define VETERINARIO_H
#include "funcionario.h"



class Veterinario : public Funcionario 
{

public:
	Veterinario();
	Veterinario(int id, string nome, string cpf, short idade, short tipo_sanguineo, char fatorRH, string especialidade);
    ~Veterinario();
	void impress();


};


#endif