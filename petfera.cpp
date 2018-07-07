#include "petfera.h"


PetFera::PetFera()
{
}


/*void PetFera::CadastrarTrat()
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
}*/

void PetFera::consultarAnimal(string key)
{

	if(key == "Mammalia" || key == "Reptilia" || key == "Aves" || key == "Amphibia")
	{
		for(auto i = mapaAnimais.begin(); i != mapaAnimais.end(); ++i)
		{
			if(i->second.get()->getAnClasse() == key)
			{
				cout << i->first << " =v " << endl;
				i->second.get()->impress();
			}
			else
			{
				cout << "Animal(is) não encontrado(s)..." << endl;
			}
		}
	}
	else
	{
		for(auto i = mapaAnimais.begin(); i != mapaAnimais.end(); ++i)
		{
			if(i->second.get()->getAnBatismo() == key)
			{
				cout << "Id: " << i->first << " =v " << endl;
				i->second.get()->impress();
			}
			else
			{
				cout << "Animal não encontrado..." << endl;
			}
		}
	}
}

void PetFera::menu()
{
	int id = 0;
	bool sair = false;
	while(sair == false)
	{
		int input;
		cout << "Bem-vindo ao PetFera." << endl;
		cout << endl;
		cout << "(1) Cadastro de animais" << endl;
		cout << "(2) Remoção de animal" << endl;
		cout << "(3) Alteração de dados de um animal" << endl;
		cout << "(4) Consulta de animal por nome ou classe" << endl;
		cout << "(5) Consulta de animal por veterinário ou tratador" << endl;
		cout << "(6) Cadastro de tratador" << endl;
		cout << "(7) Cadastro de veterinário" << endl;
		cout << "(0) Sair" << endl;
		cout << endl;
		cout << "Opção escolhida: ";
		cin >> input;
		switch(input)
		{
			case 0:
			{
				sair = true;
				break;
			}
			case 1:
			{
				//CadastrarAnimal();
				break;
			}
			case 2:
			{
				cout << "Digite o ID do animal a ser removido: ";
				cin >> id;
				//RemoverAnimal(id);
				break;
			}
			case 3:
			{
				cout << "Digite o ID do animal a ser alterado: ";
				cin >> id;
				//AlteracaoCadastro();
				break;
			}
			case 4:
			{
				string key;
				cout << "Digite o nome ou a classe do animal a ser consultado: ";
				cin >> key;
				this->consultarAnimal(key);
				break;
			}
			case 5:
			{
				//consultaPorFuncionario();
				break;
			}
			case 6:
			{
				//CadastrarTrat();
				break;
			}
			case 7:
			{
				//CadastrarVet();
				break;
			}

		}
	}
}