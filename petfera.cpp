#include "petfera.h"

PetFera::PetFera()
{
}


void PetFera::CadastrarTrat()
{
	ofstream arqWrite("funcionarios.csv", std::ios_base::app);

	if(arqWrite.bad())
	{
		cerr << "Arquivo funcionários não foi aberto corretamente" << endl;
	}

	else
	{
		arqWrite << t.getId() << ";" << "Tratador;" << t.getNome() << ";" << t.getCpf()
		 << ";" << t.getIdade() << ";" << t.getTipoSanguineo() << ";" << t.getFatorRH() << ";" << t.getEspecialidade() << endl;
	}

	arqWrite.close();
}