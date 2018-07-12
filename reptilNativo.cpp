#include "reptilNativo.h"

ReptilNativo::ReptilNativo()
{

}

ReptilNativo::ReptilNativo(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, bool venenoso, string tipoVeneno,
		string ibama, string uf_origem, string autorizacao)
:Nativo(ibama, uf_origem, autorizacao), Reptil(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, venenoso, tipoVeneno) {}


ReptilNativo::~ReptilNativo()
{

}

ostream& ReptilNativo::print(ostream &o)
{
	o << a_id << ";" << a_classe << ";" << a_nome << ";" << a_nomeCient << ";" << a_sexo << ";" << a_tamanho << ";" << a_dieta << ";" << a_vet.getId() << ";" << a_trat.getId() << ";" << a_batismo <<
	";" << a_venenoso << ";" << a_tipoVeneno << ";" << m_ibama << ";" << a_uf_origem << ";" << a_autorizacao;
	return o;
}