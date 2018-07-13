#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

using namespace std;

#include <string>
#include <iostream>

/**@brief Classe base Abstrata Funcionário*/
class Funcionario
{
protected:
	/**@brief Id do Funcionário*/
	int m_id; 
	/**@brief Nome do Funcionário*/
	string m_nome;
	/**@brief CPF do Funcionário*/
	string m_cpf; 
	/**@brief Idade do Funcionário*/
	short m_idade;
	/**@brief Tipo Sanguíneo do Funcionário*/
	string m_tipo_sanguineo; 
	/**@brief Fator RH do funcionário*/
	char m_fatorRH; 
	/**@brief Especialidade animal do Funcionário*/
	string m_especialidade;
public:
	/**@brief Construtor padrão*/
	Funcionario();
	/**@brief Construtor Parametrizado*/
	Funcionario(int id, string nome, string cpf, short idade, string tipo_sanguineo, char fatorRH, string especialidade);
	/**@brief Destrutor Padrão*/
	~Funcionario();

	//setters
	/**@brief Setter para o Id*/
	void setId(int id); 
	/**@brief Setter para o nome*/
	void setNome(string nome);
	/**@brief Setter para o CPF*/
	void setCpf(string cpf); 
	/**@brief Setter para a Idade*/
	void setIdade(short idade); 
	/**@brief Setter para o tipo sanguíneo*/
	void setTipoSanguineo(string tipo_sanguineo); 
	/**@brief Setter para o Fator RH*/
	void setFatorRH(char fatorRH); 
	/**@brief Setter para a Especialidade*/
	void setEspecialidade(string especialidade); 

	//getters
	/**@brief Getter para o ID*/
	int getId(); 
	/**@brief Getter para o Nome*/
	string getNome(); 
	/**@brief Getter para o CPF*/
	string getCpf(); 
	/**@brief Getter para a idade*/
	short getIdade(); 
	/**@brief Getter para o Tipo Sanguíneo*/
	string getTipoSanguineo(); 
	/**@brief Getter para o Fator RH*/
	char getFatorRH(); 
	/**@brief Getter para a Especialidade*/
	string getEspecialidade(); 

	virtual void impress() = 0;
	/**@brief Sobrecarga do Operador de inserção para a classe funcionário e suas classes Derivadas*/
	friend ostream& operator<< (ostream &o, Funcionario &f);
	virtual ostream& print(ostream&) = 0;



};


#endif