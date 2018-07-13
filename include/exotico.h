#ifndef EXOTICO_H
#define EXOTICO_H
#include "animalSilvestre.h"

/**@brief Classe Exotico que herda da classe Animal Silvestre*/
class Exotico : public AnimalSilvestre
{

	protected:
		/**@brief Local de Origem do animal*/
		string m_paisOrigem; 

	public:
		Exotico();
		Exotico(string ibama, string paisOrigem);
		~Exotico();

		void impress();
};

#endif