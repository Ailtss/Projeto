#ifndef ANIMAL_H
#define ANIMAL_H

#include "veterinario.h"
#include "tratador.h"

class Animal : public Veterinario, public Tratador
{
protected:
	int a_id;
	string a_classe;
	string a_nome;
	string a_nomeCient;
	char a_sexo;
	float a_tamanho;
	string a_dieta;
	Veterinario a_vet;
	Tratador a_trat;
	string a_batismo;

public:
	Animal();
	Animal(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo);
	~Animal();

	//setters

	void setAnId(int id);
	void setAnClasse(string classe);
	void setAnNome(string nome);
	void setAnNomeCient(string nomeCient);
	void setAnSexo(char sexo);
	void setAnTamanho(float tamanho);
	void setAnDieta(string dieta);
	void setAnVet(Veterinario vet);
	void setAnTrat(Tratador trat);
	void setAnBatismo(string batismo);

	//getters

	int getAnId();
	string getAnClasse();
	string getAnNome();
	string getAnNomeCient();
	char getAnSexo();
	float getAnTamanho();
	string getAnDieta();
	Veterinario getAnVet();
	Tratador getAnTrat();
	string getAnBatismo();

	void impress();

	friend ostream& operator<< (ostream &o, Animal &a); 
	virtual ostream& print(ostream&) = 0;



};



#endif