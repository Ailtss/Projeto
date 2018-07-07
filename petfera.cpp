#include "petfera.h"


PetFera::PetFera()
{
}


void PetFera::CadastrarTrat()
{
	Tratador t;
	int ID;
	short idade;
	string aux;
	char fator;

	cout << "Digite o ID do tratador: ";
	getline(cin, ID);
	t.setId(ID);
	 cin.ignore();
	cout << "Digite o nome do tratador: ";
	getline(cin, aux);
	t.setNome(aux);
	 cin.ignore();
	cout << "Digite o cpf do tratador: ";
	getline(cin, aux);
	t.setCpf(aux);
	
	cout << "Digite a idade do tratador: ";
	getline(cin,idade);
	t.setIdade(idade);
	cin.ignore();
	cout << "Digite o tipo sanguíneo do tratador: ";
	getline(cin, aux);
	t.setTipoSanguineo(aux);
	 cin.ignore();
	cout << "Digite o fator RH do tratador: ";
	getline(cin, fator);
	t.setFatorRH(fator);
	cout << "Digite a especialidade do tratador: ";
	getline(cin, aux);
	t.setEspecialidade(aux);
	 cin.ignore();
	//mapaFuncionarios.insert(pair<int, shared_ptr<Funcionario>>(t.getId(), make_shared<Funcionario>(t.getId(), t.getNome(), t.getCpf(), t.getIdade(), t.getTipoSanguineo(), t.getFatorRH(), t.getEspecialidade())));


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