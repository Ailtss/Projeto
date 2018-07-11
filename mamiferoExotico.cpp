#include "mamiferoExotico.h"

MamiferoExotico::MamiferoExotico()
{

}

MamiferoExotico::MamiferoExotico(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, string corPelo,
		string ibama, string paisOrigem)
:Exotico(ibama, paisOrigem), Mamifero(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, corPelo) {}


MamiferoExotico::~MamiferoExotico()
{

} 

ostream& MamiferoExotico::print(ostream &o)
{
	o << a_id << ";" << a_classe << ";" << a_nome << ";" << a_nomeCient << ";" << a_sexo << ";" << a_tamanho << ";" << a_dieta << a_vet.getId() << ";" << a_trat.getId() << ";" << a_batismo
	<< ";" << a_corPelo << ";" << m_ibama << ";" << m_paisOrigem;
	return o;
}