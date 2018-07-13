#ifndef ANIMALSILVESTRE_H
#define ANIMALSILVESTRE_H

using namespace std;

#include <string>
#include <iostream>
/**@brief Classe Animal Silvestre*/
class AnimalSilvestre
{
protected:
	 /**@brief Atributo responsável por guardar o ibama do animal*/
	string m_ibama;
public:
	AnimalSilvestre();
	AnimalSilvestre(string ibama);
	~AnimalSilvestre();

	//setters
	 /**@brief Setter para o ibama*/
	void setIbama(string ibama);

	//getters
	/**@brief Getter para o ibama*/
	string getIbama();

};

#endif