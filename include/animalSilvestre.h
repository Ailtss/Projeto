#ifndef ANIMALSILVESTRE_H
#define ANIMALSILVESTRE_H

using namespace std;

#include <string>
#include <iostream>

class AnimalSilvestre
{
protected:
	string m_ibama;
public:
	AnimalSilvestre();
	AnimalSilvestre(string ibama);
	~AnimalSilvestre();

	//setters
	void setIbama(string ibama);

	//getters
	string getIbama();

};

#endif