#include "animalSilvestre.h"

animalSilvestre::animalSilvestre()
{

}

animalSilvestre::animalSilvestre(string ibama)
{
	m_ibama = ibama;
}

animalSilvestre::~animalSilvestre()
{

}

//setters
void animalSilvestre::setIbama(string ibama)
{
	m_ibama = ibama;
}

//getters
string animalSilvestre::getIbama()
{
	return m_ibama;
}