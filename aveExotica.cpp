#include "aveExotica.h"

AveExotica::AveExotica()
{

}

AveExotica::AveExotica(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
	string dieta, Veterinario vet, Tratador trat, string batismo, int tamanhoBico, int envergadura, string ibama, string paisOrigem)
:Ave(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, tamanhoBico, envergadura), Exotico(ibama, paisOrigem)
{

}

AveExotica::~AveExotica()
{

}

ostream& AveExotica::print(ostream &o)
{
	o << a_id << ";" << a_classe << ";" << a_nome << ";" << a_nomeCient << ";" << a_sexo << ";" << a_tamanho << ";" << a_dieta << a_vet.getId() << ";" << a_trat.getId() << ";" << a_batismo << ";"
	<< a_tamanhoBico << ";" << a_envergadura << ";" << m_ibama << ";" << m_paisOrigem;
	return o;
}