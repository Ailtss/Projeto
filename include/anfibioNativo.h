#ifndef ANFIBIONATIVO_H
#define ANFIBIONATIVO_H

#include "anfibio.h"
#include "nativo.h"
/**@brief Classe Derivada da classe Nativo e da classe Anfibio*/
class AnfibioNativo : public Nativo, public Anfibio
{

public:
	AnfibioNativo();
	AnfibioNativo(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, int totalMudas, string ultimaMuda,
		string ibama, string uf_origem, string autorizacao);
	~AnfibioNativo();
	
	ostream& print(ostream &o);

};

#endif