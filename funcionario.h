#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

using namespace std;

#include <string>
#include <iostream>

class Funcionario
{
protected:
	int m_id;
	string m_nome;
	string m_cpf;
	short m_idade;
	string m_tipo_sanguineo;
	char m_fatorRH;
	string m_especialidade; //Tipo de animal em que o mesmo é especialista;
public:
	Funcionario();
	Funcionario(int id, string nome, string cpf, short idade, string tipo_sanguineo, char fatorRH, string especialidade);
	~Funcionario();

	//setters
	void setId(int id);
	void setNome(string nome);
	void setCpf(string cpf);
	void setIdade(short idade);
	void setTipoSanguineo(string tipo_sanguineo);
	void setFatorRH(char fatorRH);
	void setEspecialidade(string especialidade);

	//getters

	int getId();
	string getNome();
	string getCpf();
	short getIdade();
	string getTipoSanguineo();
	char getFatorRH();
	string getEspecialidade();

	virtual void impress() = 0;



};


#endif