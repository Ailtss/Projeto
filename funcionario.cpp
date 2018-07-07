#include "funcionario.h"

Funcionario::Funcionario()
{
	m_id = 0;
	m_nome = "";
	m_cpf = "";
	m_idade = 0;
	m_tipo_sanguineo = "";
	m_fatorRH = 0;
	m_especialidade = "";
}


Funcionario::Funcionario(int id, string nome, string cpf, short idade, string tipo_sanguineo, char fatorRH, string especialidade)
{
	m_id = id;
	m_nome = nome;
	m_cpf = cpf;
	m_idade = idade;
	m_tipo_sanguineo = tipo_sanguineo;
	m_fatorRH = fatorRH;
	m_especialidade = especialidade;
}


Funcionario::~Funcionario()
{

}


//setters
void Funcionario::setId(int id)
{
	m_id = id;
}

void Funcionario::setNome(string nome)
{
	m_nome = nome;
}

void Funcionario::setCpf(string cpf)
{
	m_cpf = cpf;
}

void Funcionario::setIdade(short idade)
{
	m_idade = idade;
}

void Funcionario::setTipoSanguineo(string tipo_sanguineo)
{
	m_tipo_sanguineo = tipo_sanguineo;
}

void Funcionario::setFatorRH(char fatorRH)
{
	m_fatorRH = fatorRH;
}

void Funcionario::setEspecialidade(string especialidade)
{
	m_especialidade = especialidade;
}

//getters
int Funcionario::getId()
{
	return m_id;
}

string Funcionario::getNome()
{
	return m_nome;
}

string Funcionario::getCpf()
{
	return m_cpf;
}

short Funcionario::getIdade()
{
	return m_idade;
}

string Funcionario::getTipoSanguineo()
{
	return m_tipo_sanguineo;
}

char Funcionario::getFatorRH()
{
	return m_fatorRH;
}

string Funcionario::getEspecialidade()
{
	return m_especialidade;
}

/*
void Funcionario::impress()
{
	cout << "Funcionário: " << m_nome << endl;
	cout << m_id << endl;
	cout << m_cpf << endl;
	cout << m_idade << endl;
	cout << m_tipo_sanguineo << endl;
	cout << m_fatorRH << endl;
	cout << m_especialidade << endl;

	cout << "Done." << endl;
}

*/

