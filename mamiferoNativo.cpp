#include "mamiferoNativo.h"

MamiferoNativo::MamiferoNativo()
{

}

MamiferoNativo::MamiferoNativo(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, string corPelo,
		string ibama, string uf_origem, string autorizacao)
:Nativo(ibama, uf_origem, autorizacao), Mamifero(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, corPelo) {}


MamiferoNativo::~MamiferoNativo()
{

} 

ostream& MamiferoNativo::print(ostream &o)
{
	o << a_id << ";" << a_classe << ";" << a_nome << ";" << a_nomeCient << ";" << a_sexo << ";" << a_tamanho << ";" << a_dieta << a_vet.getId() << ";" << a_trat.getId() << ";" << a_batismo
	<< ";" << a_corPelo << ";" << m_ibama << ";" << a_uf_origem << ";" << a_autorizacao;
	return o;
}