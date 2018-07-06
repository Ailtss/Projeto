#include "tratador.h"


Tratador::Tratador()
{

}

Tratador::Tratador(int id, string nome, string cpf, short idade, short tipo_sanguineo, char fatorRH, string especialidade)
:Funcionario(id, nome, cpf, idade, tipo_sanguineo, fatorRH, especialidade) {}


Tratador::~Tratador()
{

}


void Tratador::impress()
{
	cout << "Funcionário Tratador: " << m_nome << endl;
	cout << m_id << endl;
	cout << m_cpf << endl;
	cout << m_idade << endl;
	cout << m_tipo_sanguineo << endl;
	cout << m_fatorRH << endl;
	cout << m_especialidade << endl;

	cout << "Done." << endl;
}

