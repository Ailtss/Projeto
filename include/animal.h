#ifndef ANIMAL_H
#define ANIMAL_H

#include "veterinario.h"
#include "tratador.h"
/*@brief Classe base abstrata Animal**/
class Animal : public Veterinario, public Tratador
{
protected:
	/**@brief Id do Animal */
	int a_id;
	/**@brie Classe do Animal*/
	string a_classe;
	/**@brief Nome do Animal*/ 
	string a_nome;
	/**@brief Nome científico do Animal*/
	string a_nomeCient;
	/**@brief Sexo do Animal*/ 
	char a_sexo; 
	/**@brief Tamanho do Animal*/
	float a_tamanho;
	/**@brief Dieta do Animal*/
	string a_dieta; 
	/**@brief Objeto para a classe Veterinário*/
	Veterinario a_vet; 
	/**@brief Objeto para a classe Tratador*/
	Tratador a_trat;
	/**@brief Objeto para o nome de batismo*/
	string a_batismo;

public:
	/**@brief Construtor padrão */
	Animal(); 
	/**@brief Construtor parametrizado*/
	Animal(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo); 
	/**@brief Destrutor padrão*/
	~Animal(); 

	//setters
	/**@brief Setter para o ID*/
	void setAnId(int id); 
	/**@brief Setter para a classe*/
	void setAnClasse(string classe);
	/**@brief Setter para o nome*/
	void setAnNome(string nome);
	 /**@brief Setter para o Nome Científico*/
	void setAnNomeCient(string nomeCient);
	/**@brief Setter para o sexo do Animal*/
	void setAnSexo(char sexo);
	/**@brief Setter para o tamanho*/
	void setAnTamanho(float tamanho);
	/**@brief Setter para a Dieta*/
	void setAnDieta(string dieta);
	/**@brief Setter para o objeto Veterinário*/
	void setAnVet(Veterinario vet);
	/**@brief Setter para o objeto Tratador*/
	void setAnTrat(Tratador trat);
	/**@brief Setter para o nome de Batismo*/
	void setAnBatismo(string batismo);

	//getters
	/**@brief Getter para o Id*/
	int getAnId(); 
	/**@brief Getter para a Classe*/
	string getAnClasse(); 
	 /**@brief Getter para o Nome*/
	string getAnNome();
	 /**@brief Getter para o Nome Científico*/
	string getAnNomeCient();
	 /**@brief Getter para o Sexo*/
	char getAnSexo();
	 /**@brief Getter para o tamanho*/
	float getAnTamanho();
	/**@brief Getter para a Dieta*/
	string getAnDieta();
	/**@brief Getter para o objeto  Veterinário*/
	Veterinario getAnVet(); 
	/**@brief Getter para o objeto Tratador*/
	Tratador getAnTrat(); 
	/**@brief Getter para o nome de Batismo*/
	string getAnBatismo(); 

	void impress();
	 /**@brief Sobrecarga do Operador de Inserção para a classe Animal e suas Derivadas*/
	friend ostream& operator<< (ostream &o, Animal &a);
	/**@brief Método Virtual para tornar a classe Abstrata*/
	virtual ostream& print(ostream&) = 0; 



};



#endif