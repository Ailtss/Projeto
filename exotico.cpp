#include "exotico.h"

Exotico::Exotico()
{

}

Exotico::Exotico(string ibama, string paisOrigem)
:AnimalSilvestre(ibama)
{
	m_paisOrigem = paisOrigem;
}

Exotico::~Exotico()
{

}

void Exotico::impress()
{
	cout << "Ibama: " << a_ibama << endl;

	cout << "Características Exotico: " << endl;
	cout << "Pais de origem: " << m_paisOrigem << endl;
}