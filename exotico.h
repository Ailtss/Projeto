#ifndef EXOTICO_H
#define EXOTICO_H
#include "animalSilvestre.h"

class Exotico : public AnimalSilvestre
{

	protected:
		string m_paisOrigem;

	public:
		Exotico();
		Exotico(string ibama, string paisOrigem);
		~Exotico();

		void impress();
}