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

	Veterinario dois(13, "Figueira Dantas","070931384-54", 20, "O", '+', "Aves");

	Tratador tres(26, "Ramos da Silva", "070931384-54", 22, "AB", '-', "Répteis");

	mapaAnimais.insert(pair<int, shared_ptr<Animal>>(15, make_shared<Mamifero>(15, "Mammalia", "Leão", "Panthera Leo", 'M', 2, "Carne", dois, tres, "Simba", "Dourado")));
	mapaAnimais.insert(pair<int, shared_ptr<Animal>>(16, make_shared<Mamifero>(16, "Mammalia", "Pantera", "Panthera Leo", 'M', 2, "Carne", dois, tres, "Mustaf", "Preto")));
	mapaAnimais.insert(pair<int, shared_ptr<Animal>>(01, make_shared<Ave>(01, "Aves", "Águia", "Aquila Adalberti", 'M', 2, "Grãos", dois, tres, "Ícaro", 10, 15)));
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

void PetFera::RemoveFuncionario(int id)
{
	ifstream arqLer("funcionarios.csv");

	if(arqLer.bad())
	{
		cerr << "Arquivo funcionário não foi aberto corretamente" << endl;
	}

	else
	{
		int contLinha = 0;
		vector<string> s_vetor;
		string linha;
		string s;
		string aux = "";
		int valor = 0;

		while(getline(arqLer, linha))
		{
			s_vetor.push_back(linha);

		}

		arqLer.close();

		ifstream file("funcionarios.csv");

		while(getline(file, linha))
		{
			getline(file, s, ';');
			contLinha++;
			aux = s;
			valor = stoi(s);
			if(valor == id)
			{
				break;
			}
			
		}

		file.close();

		ofstream arqWrite("funcionarios.csv");



		s_vetor.erase(s_vetor.begin()+contLinha);


		for(unsigned int i = 0; i < s_vetor.size(); i++)
		{
			arqWrite << s_vetor[i] << endl;
		}


		arqWrite.close();

	}
}

void PetFera::RemoveAnimal(int id)
{
	ifstream arqLer("animais.csv");

	if(arqLer.bad())
	{
		cerr << "Arquivo Animal não foi aberto corretamente" << endl;
	}

	else
	{
		int contLinha = 0;
		vector<string> s_vetor;
		string linha;
		string s;
		string aux = "";
		int valor = 0;

		while(getline(arqLer, linha))
		{
			s_vetor.push_back(linha);

		}

		arqLer.close();

		ifstream file("animais.csv");

		while(getline(file, linha))
		{
			getline(file, s, ';');
			contLinha++;
			aux = s;
			valor = stoi(s);
			if(valor == id)
			{
				break;
			}
			
		}

		file.close();

		ofstream arqWrite("animais.csv");



		s_vetor.erase(s_vetor.begin()+contLinha);


		for(unsigned int i = 0; i < s_vetor.size(); i++)
		{
			arqWrite << s_vetor[i] << endl;
		}


		arqWrite.close();

	}
}

void PetFera::cadastrarTrat(Tratador t)
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

void PetFera::cadastrarVet(Veterinario v)
{
	ofstream arqWrite("funcionarios.csv", std::ios_base::app);

	if(arqWrite.bad())
	{
		cerr << "Arquivo funcionários não foi aberto corretamente" << endl;
	}

	else
	{
		arqWrite << v.getId() << ";" << "Veterinário;" << v.getNome() << ";" << v.getCpf()
		 << ";" << v.getIdade() << ";" << v.getTipoSanguineo() << ";" << v.getFatorRH() << ";" << v.getEspecialidade() << endl;
	}

	arqWrite.close();
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