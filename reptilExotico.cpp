#include "reptilExotico.h"

ReptilExotico::ReptilExotico()
{

}

ReptilExotico::ReptilExotico(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, bool venenoso, string tipoVeneno,
		string ibama, string paisOrigem)
:Exotico(ibama, paisOrigem), Reptil(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, venenoso, tipoVeneno) {}


ReptilExotico::~ReptilExotico()
{

}

ostream& ReptilExotico::print(ostream &o)
{
	o << a_id << ";" << a_classe << ";" << a_nome << ";" << a_nomeCient << ";" << a_sexo << ";" << a_tamanho << ";" << a_dieta << ";" << a_vet.getId() << ";" << a_trat.getId() << ";" << a_batismo <<
	";" << a_venenoso << ";" << a_tipoVeneno << ";" << m_ibama << ";" << m_paisOrigem;
	return o;
}