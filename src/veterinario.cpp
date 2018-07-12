#include "veterinario.h"

Veterinario::Veterinario()
{

}

Veterinario::Veterinario(int id, string nome, string cpf, short idade, string tipo_sanguineo, char fatorRH, string especialidade)
:Funcionario(id, nome, cpf, idade, tipo_sanguineo, fatorRH, especialidade) {}



Veterinario::~Veterinario()
{

}


void Veterinario::impress()
{

	cout << "Funcionário Veterinário: " << m_nome << endl;
	cout << m_id << endl;
	cout << m_cpf << endl;
	cout << m_idade << endl;
	cout << m_tipo_sanguineo << endl;
	cout << m_fatorRH << endl;
	cout << m_especialidade << endl;

	cout << "Done." << endl;


}

ostream& Veterinario::print(ostream& o)
{
	o << m_id << ";" << "Veterinário" << ";" << m_nome << ";" << m_cpf << ";" << m_idade << ";"
	<< m_tipo_sanguineo << ";" << m_fatorRH << ";" << m_especialidade;
	return o;
}