#ifndef ANIMALSILVESTRE_H
#define ANIMALSILVESTRE_H

using namespace std;

#include <string>

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

	virtual void impress() = 0;

};

#endif