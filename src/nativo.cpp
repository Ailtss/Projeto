#include "nativo.h"

Nativo::Nativo()
{

}

Nativo::Nativo(string ibama, string uf_origem, string autorizacao):AnimalSilvestre(ibama)
{
	a_uf_origem = uf_origem;
	a_autorizacao = autorizacao;
}

Nativo::~Nativo()
{

}

