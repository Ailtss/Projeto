#include "animalSilvestre.h"

AnimalSilvestre::AnimalSilvestre()
{

}

AnimalSilvestre::AnimalSilvestre(string ibama)
{
	m_ibama = ibama;
}

AnimalSilvestre::~AnimalSilvestre()
{

}

//setters
void AnimalSilvestre::setIbama(string ibama)
{
	m_ibama = ibama;
}

//getters
string AnimalSilvestre::getIbama()
{
	return m_ibama;
}