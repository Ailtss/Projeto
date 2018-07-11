#include "anfibioNativo.h"

AnfibioNativo::AnfibioNativo()
{

}

AnfibioNativo::AnfibioNativo(int id, string classe, string nome, string nomeCient, char sexo, float tamanho,
		string dieta, Veterinario vet, Tratador trat, string batismo, int totalMudas, string ultimaMuda,
		string ibama, string uf_origem, string autorizacao)
:Nativo(ibama, uf_origem, autorizacao), Anfibio(id, classe, nome, nomeCient, sexo, tamanho, dieta, vet, trat, batismo, totalMudas, ultimaMuda) {}


AnfibioNativo::~AnfibioNativo()
{

}

ostream& AnfibioNativo::print(ostream &o)
{
	o << a_id << ";" << a_classe << ";" << a_nome << ";" << a_nomeCient << ";" << a_sexo << ";" << a_tamanho << ";" << a_dieta << a_vet.getId() << ";" << a_trat.getId() << ";" << a_batismo << ";"
	<< a_totalMudas << ";" << a_ultimaMuda << ";" << m_ibama << ";" << a_uf_origem << ";" << a_autorizacao;
	return o;
}

