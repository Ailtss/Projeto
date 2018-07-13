#include "PetFera.h"

PetFera::PetFera()
{

}

PetFera::~PetFera()
{

}

void PetFera::init()
{
	ifstream Funcionarios("data/funcionarios.csv");
	vector<string> dadosLinha;

	if(!Funcionarios.bad())
	{
		while(!Funcionarios.eof())
		{
			string linhas;
			string dado;
			getline(Funcionarios, linhas, '\n');
			istringstream linha(linhas);

			while(getline(linha, dado, ';'))
			{
				dadosLinha.push_back(dado);
			}
			
			if(dadosLinha[1] == "Tratador")
			{

				int aux = stoi(dadosLinha[0]);
				short idade = stoi(dadosLinha[3]);

				shared_ptr<Tratador> f = make_shared<Tratador>(aux, dadosLinha[2], dadosLinha[3], idade, dadosLinha[5], *(dadosLinha[6].c_str()), dadosLinha[7]);
				this->mapaTratadores.insert(pair<int, shared_ptr<Tratador>>(aux, f));
			}

			else
			{
				int aux = stoi(dadosLinha[0]);
				short idade = stoi(dadosLinha[3]);

				shared_ptr<Veterinario> f = make_shared<Veterinario>(aux, dadosLinha[2], dadosLinha[3], idade, dadosLinha[5], *(dadosLinha[6].c_str()), dadosLinha[7]);
				this->mapaVeterinarios.insert(pair<int, shared_ptr<Veterinario>>(aux, f));
			}

			dadosLinha.clear();
		}
	}

	else
	{
		cerr << "Arquivo de Funcionários não foi aberto corretamente!" << endl;
	}

	Funcionarios.close();

	ifstream Animais("data/animais.csv");
	if(!Animais.bad())
	{
		while(!Animais.eof())
		{
			string linhas;
			string dado;
			getline(Animais, linhas, '\n');
			istringstream linha(linhas);
			while(getline(linha, dado, ';'))
			{
				dadosLinha.push_back(dado);
			}
			int idVet = stoi(dadosLinha[7]);
			int idTrat = stoi(dadosLinha[8]);
			if(dadosLinha[1] == "Mammalia")
			{
				if(dadosLinha[13] != "")
				{
					int aux = stoi(dadosLinha[0]);
					shared_ptr<Animal> m = make_shared<MamiferoNativo>(stoi(dadosLinha[0]), dadosLinha[1], dadosLinha[2], dadosLinha[3], *(dadosLinha[4].c_str()), stof(dadosLinha[5]),
					dadosLinha[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dadosLinha[9], dadosLinha[10], dadosLinha[11], dadosLinha[12], dadosLinha[13]);
					this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(aux, m));
				}
				else
				{
					int aux = stoi(dadosLinha[0]);
					shared_ptr<Animal> m = make_shared<MamiferoExotico>(stoi(dadosLinha[0]), dadosLinha[1], dadosLinha[2], dadosLinha[3], *(dadosLinha[4].c_str()), stof(dadosLinha[5]),
					dadosLinha[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dadosLinha[9], dadosLinha[10], dadosLinha[11], dadosLinha[12]);
					this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(aux, m));
				}
			}
			else if(dadosLinha[1] == "Aves")
			{
				if(dadosLinha[14] != "")
				{
					int aux = stoi(dadosLinha[0]);
					shared_ptr<Animal> m = make_shared<AveNativa>(stoi(dadosLinha[0]), dadosLinha[1], dadosLinha[2], dadosLinha[3], *(dadosLinha[4].c_str()), stof(dadosLinha[5]),
					dadosLinha[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dadosLinha[9], stoi(dadosLinha[10]), stoi(dadosLinha[11]), dadosLinha[12], dadosLinha[13], dadosLinha[14]);
					this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(aux, m));
				}
				else
				{
					int aux = stoi(dadosLinha[0]);
					shared_ptr<Animal> m = make_shared<AveExotica>(stoi(dadosLinha[0]), dadosLinha[1], dadosLinha[2], dadosLinha[3], *(dadosLinha[4].c_str()), stof(dadosLinha[5]),
					dadosLinha[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dadosLinha[9], stoi(dadosLinha[10]), stoi(dadosLinha[11]), dadosLinha[12], dadosLinha[13]);
					this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(aux, m));
				}
			}
			else if(dadosLinha[1] == "Reptilia")
			{
				if(dadosLinha[14] != "")
				{
					int aux = stoi(dadosLinha[0]);
					bool venenoso = false;
					if(dadosLinha[10] == "true")
					{
						venenoso = true;
					}
					shared_ptr<Animal> m = make_shared<ReptilNativo>(stoi(dadosLinha[0]), dadosLinha[1], dadosLinha[2], dadosLinha[3], *(dadosLinha[4].c_str()), stof(dadosLinha[5]),
					dadosLinha[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dadosLinha[9], venenoso, dadosLinha[11], dadosLinha[12], dadosLinha[13], dadosLinha[14]);
					this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(aux, m));
				}
				else
				{
					int aux = stoi(dadosLinha[0]);
					bool venenoso = false;
					if(dadosLinha[10] == "true")
					{
						venenoso = true;
					}
					shared_ptr<Animal> m = make_shared<ReptilExotico>(stoi(dadosLinha[0]), dadosLinha[1], dadosLinha[2], dadosLinha[3], *(dadosLinha[4].c_str()), stof(dadosLinha[5]),
					dadosLinha[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dadosLinha[9], venenoso, dadosLinha[11], dadosLinha[12], dadosLinha[13]);
					this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(aux, m));
				}
			}
			else if(dadosLinha[1] == "Amphibia")
			{
				if(dadosLinha[14] != "")
				{
					int aux = stoi(dadosLinha[0]);
					shared_ptr<Animal> m = make_shared<AnfibioNativo>(stoi(dadosLinha[0]), dadosLinha[1], dadosLinha[2], dadosLinha[3], *(dadosLinha[4].c_str()), stof(dadosLinha[5]),
					dadosLinha[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dadosLinha[9], stoi(dadosLinha[10]), dadosLinha[11], dadosLinha[12], dadosLinha[13], dadosLinha[14]);
					this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(aux, m));
				}
				else
				{
					int aux = stoi(dadosLinha[0]);
					shared_ptr<Animal> m = make_shared<AnfibioExotico>(stoi(dadosLinha[0]), dadosLinha[1], dadosLinha[2], dadosLinha[3], *(dadosLinha[4].c_str()), stof(dadosLinha[5]),
					dadosLinha[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dadosLinha[9], stoi(dadosLinha[10]), dadosLinha[11], dadosLinha[12], dadosLinha[13]);
					this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(aux, m));
				}
			}
			dadosLinha.clear();
		}
	}

	else
	{
		cerr << "Arquivo de Animais não foi aberto corretamente!" << endl;
	}

	Animais.close();
}

void PetFera::clearScreen()
{
	cout << "\033[2J\033[1;1H";
}

void PetFera::cadastrarAnimalNativo()
{
	shared_ptr<Animal> print;
	vector<string> dados;
	string aux;
	int id;
	int valor;
	cout << "Informe o ID do animal: " << endl;
	getline(cin, aux);
	id = stoi(aux);
	dados.push_back(aux);

	cout << "Digite um número que indique a classe do Animal: " << endl;
	cout << "(1)Mammalia" << " " << "(2)Amphibia" << " " << "(3)Reptilia" << " " << "(4)Aves" << endl;
	getline(cin, aux);
	valor = stoi(aux);

	if(valor == 1)
	{
		dados.push_back("Mammalia");

		cout << "Informe o nome do Animal: " << endl;
		getline(cin, aux);
		cout << "Nome do Animal: " << aux << endl;
		dados.push_back(aux);

		cout << "Informe o nome científico:  " << endl;
		getline(cin, aux);
		cout << "Nome Científico do Animal: " << aux << endl;
		dados.push_back(aux);

		cout << "Informe o sexo do animal(M/F): " << endl;
		getline(cin, aux);
		cout << "Sexo do animal: " << aux << endl;
		dados.push_back(aux);

		cout << "Informe o tamanho do animal: " << endl;
		getline(cin, aux);
		cout << "Tamanho do animal: " << aux << endl;
		dados.push_back(aux);

		cout << "Informe a dieta do animal: " << endl;
		getline(cin, aux);
		cout << "Dieta do Animal: " << aux << endl;
		dados.push_back(aux);

		cout << "Informe o ID do Veterinário do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Veterinário digite 0." << endl;
		getline(cin, aux);
		int idVet = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o ID do Tratador do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Tratador digite 0." << endl;
		getline(cin, aux);
		int idTrat = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o nome de batismo do animal: " << endl;
		getline(cin, aux);
		cout << "Nome de bastismo do animal: " << aux << endl;
		dados.push_back(aux);

		cout << "Informe a cor do pelo do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o Ibama do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a UF de origem do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a Autorização do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		shared_ptr<Animal> m = make_shared<MamiferoNativo>(stoi(dados[0]), dados[1], dados[2], dados[3], *(dados[4].c_str()), stof(dados[5]),
					dados[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dados[9], dados[10], dados[11], dados[12], dados[13]);
		this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(id, m));

	}

	else if(valor == 2)
	{
		dados.push_back("Amphibia");

		cout << "Informe o nome do Animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o nome científico:  " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o sexo do animal(M/F): " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o tamanho do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a dieta do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o ID do Veterinário do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Veterinário digite 0." << endl;
		getline(cin, aux);
		int idVet = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o ID do Tratador do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Tratador digite 0." << endl;
		getline(cin, aux);
		int idTrat = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o nome de batismo do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o total de mudas do animal: " << endl;
		getline(cin, aux);
		int mudas = stoi(aux);
		dados.push_back(aux);

		cout << "Informe a última muda do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o Ibama do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a UF de origem do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a Autorização do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		shared_ptr<Animal> m = make_shared<AnfibioNativo>(stoi(dados[0]), dados[1], dados[2], dados[3], *(dados[4].c_str()), stof(dados[5]),
					dados[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dados[9], mudas, dados[11], dados[12], dados[13], dados[14]);
		this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(id, m));

	}

	else if(valor == 3)
	{
		dados.push_back("Reptilia");

		cout << "Informe o nome do Animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o nome científico:  " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o sexo do animal(M/F): " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o tamanho do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a dieta do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o ID do Veterinário do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Veterinário digite 0." << endl;
		getline(cin, aux);
		int idVet = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o ID do Tratador do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Tratador digite 0." << endl;
		getline(cin, aux);
		int idTrat = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o nome de batismo do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe se o animal é venenoso (true/false): " << endl;
		getline(cin, aux);
		bool venenoso = false;
		if(aux == "true")
		{
			venenoso = true;
		}
		dados.push_back(aux);

		cout << "Informe o tipo de veneno do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o Ibama do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a UF de origem do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a Autorização do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		shared_ptr<Animal> m = make_shared<ReptilNativo>(stoi(dados[0]), dados[1], dados[2], dados[3], *(dados[4].c_str()), stof(dados[5]),
					dados[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dados[9], venenoso, dados[11], dados[12], dados[13], dados[14]);
		this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(id, m));
	}

	else
	{
		dados.push_back("Aves");

		cout << "Informe o nome do Animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o nome científico:  " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o sexo do animal(M/F): " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o tamanho do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a dieta do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o ID do Veterinário do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Veterinário digite 0." << endl;
		getline(cin, aux);
		int idVet = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o ID do Tratador do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Tratador digite 0." << endl;
		getline(cin, aux);
		int idTrat = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o nome de batismo do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe se o tamanho do bico do animal: " << endl;
		getline(cin, aux);
		int bico = stoi(aux);
		dados.push_back(aux);

		cout << "Informe a envergadura do animal: " << endl;
		getline(cin, aux);
		int envergadura = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o Ibama do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a UF de origem do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a Autorização do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		shared_ptr<Animal> m = make_shared<AveNativa>(stoi(dados[0]), dados[1], dados[2], dados[3], *(dados[4].c_str()), stof(dados[5]),
					dados[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dados[9], bico, envergadura, dados[12], dados[13], dados[14]);
		this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(id, m));
	}
	cout << endl;
}

void PetFera::cadastrarAnimalExotico()
{
	shared_ptr<Animal> print;
	vector<string> dados;
	string aux;
	int id;
	int valor;
	cout << "Informe o ID do animal: " << endl;
	getline(cin, aux);
	id = stoi(aux);
	dados.push_back(aux);

	cout << "Digite um número que indique a classe do Animal: " << endl;
	cout << "(1)Mammalia" << " " << "(2)Amphibia" << " " << "(3)Reptilia" << " " << "(4)Aves" << endl;
	getline(cin, aux);
	valor = stoi(aux);

	if(valor == 1)
	{
		dados.push_back("Mammalia");

		cout << "Informe o nome do Animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o nome científico:  " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o sexo do animal(M/F): " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o tamanho do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a dieta do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o ID do Veterinário do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Veterinário digite 0." << endl;
		getline(cin, aux);
		int idVet = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o ID do Tratador do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Tratador digite 0." << endl;
		getline(cin, aux);
		int idTrat = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o nome de batismo do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a cor do pelo do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o Ibama do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o país de origem do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		shared_ptr<Animal> m = make_shared<MamiferoExotico>(stoi(dados[0]), dados[1], dados[2], dados[3], *(dados[4].c_str()), stof(dados[5]),
					dados[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dados[9], dados[10], dados[11], dados[12]);
		this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(id, m));

	}

	else if(valor == 2)
	{
		dados.push_back("Amphibia");

		cout << "Informe o nome do Animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o nome científico:  " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o sexo do animal(M/F): " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o tamanho do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a dieta do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o ID do Veterinário do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Veterinário digite 0." << endl;
		getline(cin, aux);
		int idVet = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o ID do Tratador do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Tratador digite 0." << endl;
		getline(cin, aux);
		int idTrat = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o nome de batismo do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o total de mudas do animal: " << endl;
		getline(cin, aux);
		int mudas = stoi(aux);
		dados.push_back(aux);

		cout << "Informe a última muda do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o Ibama do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o país de origem do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		shared_ptr<Animal> m = make_shared<AnfibioExotico>(stoi(dados[0]), dados[1], dados[2], dados[3], *(dados[4].c_str()), stof(dados[5]),
					dados[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dados[9], mudas, dados[11], dados[12], dados[13]);
		this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(id, m));

	}

	else if(valor == 3)
	{
		dados.push_back("Reptilia");

		cout << "Informe o nome do Animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o nome científico:  " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o sexo do animal(M/F): " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o tamanho do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a dieta do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o ID do Veterinário do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Veterinário digite 0." << endl;
		getline(cin, aux);
		int idVet = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o ID do Tratador do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Tratador digite 0." << endl;
		getline(cin, aux);
		int idTrat = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o nome de batismo do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe se o animal é venenoso (true/false): " << endl;
		getline(cin, aux);
		bool venenoso = false;
		if(aux == "true")
		{
			venenoso = true;
		}
		dados.push_back(aux);

		cout << "Informe o tipo de veneno do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o Ibama do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o país de origem do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		shared_ptr<Animal> m = make_shared<ReptilExotico>(stoi(dados[0]), dados[1], dados[2], dados[3], *(dados[4].c_str()), stof(dados[5]),
					dados[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dados[9], venenoso, dados[11], dados[12], dados[13]);
		this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(id, m));
	}

	else
	{
		dados.push_back("Aves");

		cout << "Informe o nome do Animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o nome científico:  " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o sexo do animal(M/F): " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o tamanho do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe a dieta do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o ID do Veterinário do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Veterinário digite 0." << endl;
		getline(cin, aux);
		int idVet = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o ID do Tratador do animal: " << endl;
		cout << "Warning: Se o animal não possuir um Tratador digite 0." << endl;
		getline(cin, aux);
		int idTrat = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o nome de batismo do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe se o tamanho do bico do animal: " << endl;
		getline(cin, aux);
		int bico = stoi(aux);
		dados.push_back(aux);

		cout << "Informe a envergadura do animal: " << endl;
		getline(cin, aux);
		int envergadura = stoi(aux);
		dados.push_back(aux);

		cout << "Informe o Ibama do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		cout << "Informe o país de origem do animal: " << endl;
		getline(cin, aux);
		dados.push_back(aux);

		shared_ptr<Animal> m = make_shared<AveExotica>(stoi(dados[0]), dados[1], dados[2], dados[3], *(dados[4].c_str()), stof(dados[5]),
					dados[6], *(this->mapaVeterinarios[idVet]), *(this->mapaTratadores[idTrat]), dados[9], bico, envergadura, dados[12], dados[13]);
		this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(id, m));
	}
	cout << endl;
}

void PetFera::consultarAnimal()
{
	string consulta;
	bool achou = false;
	cout << "Digite o id do animal ou a sua classe: ";
	getline(cin, consulta);
	if(consulta == "Mammalia" || consulta == "Aves" || consulta == "Amphibia" || consulta == "Reptilia")
	{
		for(auto it = this->mapaAnimais.begin(); it != this->mapaAnimais.end(); it++)
		{
			if(it->second->getAnClasse() == consulta)
			{
				cout << *(it->second) << endl;
				achou = true;
			}
		}
		if(achou == false)
		{
			cout << "Classe de animais não encontrada mo sistema..." << endl;
		}
	}
	else
	{
		int idProcurado = stoi(consulta);
		for(auto it = this->mapaAnimais.begin(); it != this->mapaAnimais.end(); it++)
		{
			if(it->second->getAnId() == idProcurado)
			{
				cout << *(it->second) << endl;
				achou = true;
			}
		}
		if(achou == false)
		{
			cout << "Animal não encontrado no sistema..." << endl;
		}
	}
	cout << endl;
}

void PetFera::consultarPorFuncionario()
{
	int idFuncionario;
	bool achou = false;
	cout << "Digite o id do tratador ou do veterinário: ";
	cin >> idFuncionario;
	for(auto it = this->mapaAnimais.begin(); it != this->mapaAnimais.end(); it++)
	{
		if(it->second->getAnVet().getId() == idFuncionario)
		{
			cout << *(it->second) << endl;
			achou = true;
		}

		else if(it->second->getAnTrat().getId() == idFuncionario)
		{
			cout << *(it->second) << endl;
			achou = true;
		}
	}
	if(achou == false)
	{
		cout << "Não existem animais sob a responsabilidade do tratador/veterinário com id "<< idFuncionario << "..." << endl;
	}
	cout << endl;
}

bool PetFera::removerAnimal()
{
	shared_ptr<Animal> print;
	int idRemovido = 0;
	cout << "Digite o id do animal a ser removido: ";
	cin >> idRemovido;
	for(auto i = mapaAnimais.begin(); i != mapaAnimais.end(); i++)
	{
		if(i->first == idRemovido)
		{
			mapaAnimais.erase(i);
			cout << "Animal removido com sucesso!" << endl;
			cout << endl;
			return true;
		}
	}
	cout << "Animal não foi encontrado no sistema, tente novamente..." << endl;
	cout << endl;
	return false;
}

void PetFera::cadastrarVeterinario()
{
	shared_ptr<Funcionario> print;
	vector<string> dados;
	string help;

	cout << "Informe o ID do Veterinário: " << endl;
	getline(cin, help);
	dados.push_back(help);

	cout << "Informe o Nome do Veterinário: " << endl;
	getline(cin, help);
	dados.push_back(help);

	cout << "Informe o CPF do Veterinário: " << endl;
	getline(cin, help);
	dados.push_back(help);

	cout << "Informe a idade do Veterinário:" << endl;
	getline(cin, help);
	dados.push_back(help);

	cout << "Informe o tipo sanguíneo do Veterinário: " << endl;
	getline(cin, help);
	dados.push_back(help);

	cout << "Informe o fator RH do Veterinário: " << endl;
	getline(cin, help);
	dados.push_back(help);

	cout << "Informe a especialidade do Veterinário: " << endl;
	getline(cin, help);
	dados.push_back(help);

	int id = stoi(dados[0]);

	shared_ptr<Veterinario> v = make_shared<Veterinario>(id, dados[1], dados[2], stoi(dados[3]), dados[4], *(dados[5].c_str()), dados[6]);

	this->mapaVeterinarios.insert(pair<int, shared_ptr<Veterinario>>(id, v));

	cout << endl;
}


void PetFera::cadastrarTratador()
{
	shared_ptr<Tratador> print;
	vector<string> dados;
	string help;

	cout << "Informe o ID do Tratador: " << endl;
	getline(cin, help);
	dados.push_back(help);

	cout << "Informe o Nome do Tratador: " << endl;
	getline(cin, help);
	dados.push_back(help);

	cout << "Informe o CPF do Tratador: " << endl;
	getline(cin, help);
	dados.push_back(help);

	cout << "Informe a idade do Tratador:" << endl;
	getline(cin, help);
	dados.push_back(help);

	cout << "Informe o tipo sanguíneo do Tratador: " << endl;
	getline(cin, help);
	dados.push_back(help);

	cout << "Informe o fator RH do Tratador: " << endl;
	getline(cin, help);
	dados.push_back(help);

	cout << "Informe a especialidade do Tratador: " << endl;
	getline(cin, help);
	dados.push_back(help);

	int id = stoi(dados[0]);

	shared_ptr<Tratador> t = make_shared<Tratador>(id, dados[1], dados[2], stoi(dados[3]), dados[4], *(dados[5].c_str()), dados[6]);

	this->mapaTratadores.insert(pair<int, shared_ptr<Tratador>>(id, t));

	cout << endl;
}

bool PetFera::removerFuncionario()
{
	shared_ptr<Funcionario> print;
	int idRemovido = 0;
	char aux;
	cout << "Deseja remover um Tratador ou Veterinário? (T/V)" << endl;
	cin >> aux;

	if(aux == 'T')
	{
		cout << "Digite o id do Tratador a ser removido: ";
		cin >> idRemovido;
		for(auto i = mapaTratadores.begin(); i != mapaTratadores.end(); i++)
		{
			if(i->first == idRemovido)
			{
				mapaTratadores.erase(i);
				cout << "Tratador removido com sucesso!" << endl;
				cout << endl;
				return true;
			}
		}
		cout << "Funcionário não foi encontrado no sistema, tente novamente..." << endl;
		cout << endl;
		return false;
	}

	else
	{
		cout << "Digite o id do Veterinário a ser removido: ";
		cin >> idRemovido;
		for(auto i = mapaVeterinarios.begin(); i != mapaVeterinarios.end(); i++)
		{
			if(i->first == idRemovido)
			{
				mapaVeterinarios.erase(i);
				cout << "Veterinário removido com sucesso!" << endl;
				cout << endl;
				return true;
			}
		}
		cout << "Fuincionário não foi encontrado no sistema, tente novamente..." << endl;
		cout << endl;
		return false;
	}

	return false;
	
}

void PetFera::endAnimais() //Fazendo o teste só com Animais pois já está totalmente sobrecarregado
{
	ofstream Animais("data/animais.csv");
	shared_ptr<Animal> a;

	for(auto it = this->mapaAnimais.begin(); it != this->mapaAnimais.end(); ++it)
		{
			a = it->second;

			Animais << *a << endl;
    		
		}

		Animais.close();

}

void PetFera::endFuncionarios()
{
	ofstream Funcionarios("data/funcionarios.csv");
	shared_ptr<Funcionario> f;

	for(auto it = this->mapaTratadores.begin(); it != this->mapaTratadores.end(); ++it)
		{
			f = it->second;

			Funcionarios << *f << endl;
    		
		}

	for(auto it = this->mapaVeterinarios.begin(); it != this->mapaVeterinarios.end(); ++it)
		{
			f = it->second;

			Funcionarios << *f << endl;
    		
		}

		Funcionarios.close();
}

void PetFera::listarAnimais()
{
	cout << "Animais:" << endl;
	for(auto it = this->mapaAnimais.begin(); it != mapaAnimais.end(); it++)
	{
		cout << *(it->second) << endl;
	}
	cout << endl;
}

void PetFera::listarFuncionarios()
{
	cout << "Tratadores:" << endl;
	for(auto it = this->mapaTratadores.begin(); it != mapaTratadores.end(); it++)
	{
		cout << *(it->second) << endl;
	}
	cout << endl;
	cout << "Veterinários:" << endl;
	for(auto it = this->mapaVeterinarios.begin(); it != mapaVeterinarios.end(); it++)
	{
		cout << *(it->second) << endl;
	}
	cout << endl;
}



void PetFera::menu()
{
	this->init();
	bool sair = false;
	cout << "Bem-vindo ao PetFera." << endl;
	cout << endl;
	while(sair == false)
	{
		int input;
		cout << "(1) Cadastro de animais" << endl;
		cout << "(2) Remoção de animal" << endl;
		cout << "(3) Alteração de dados de um animal" << endl;
		cout << "(4) Consulta de animal por nome ou classe" << endl;
		cout << "(5) Consulta de animal por veterinário ou tratador" << endl;
		cout << "(6) Cadastro de funcionário" << endl;
		cout << "(7) Remoção de funcionário" << endl;
		cout << "(8) Listar animais" << endl;
		cout << "(9) Listar funcionarios" << endl;
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
				string aux;
				cout << "Deseja cadastrar um animal exotico ou nativo? (E/N)" << endl;
				cin.ignore();
				getline(cin, aux);
				if(aux == "E")
				{
					this->cadastrarAnimalExotico();
					break;
				}
				else if(aux == "N")
				{
					this->cadastrarAnimalNativo();
					break;
				}
				else
				{
					cout << "Tipo de animal não identificado..." << endl;
					break;
				}
			}
			case 2:
			{
				this->removerAnimal();
				break;
			}
			case 3:
			{
				cout << "Digite o ID do animal a ser alterado: ";
				//AlteracaoCadastro();
				break;
			}
			case 4:
			{
				cin.ignore();
				this->consultarAnimal();
				break;
			}
			case 5:
			{
				cin.ignore();
				this->consultarPorFuncionario();
				break;
			}
			case 6:
			{
				string aux;
				cout << "Deseja cadastrar um tratador ou um veterinário? (T/V)" << endl;
				getline(cin, aux);
				if(aux == "T")
				{
					this->cadastrarTratador();
					break;
				}
				else if(aux == "V")
				{
					this->cadastrarVeterinario();
					break;
				}
				else
				{
					cout << "Tipo de funcionário não identificado..." << endl;
					break;
				}
			}
			case 7:
			{
				this->removerFuncionario();
				break;
			}
			case 8:
			{
				this->listarAnimais();
				break;
			}
			case 9:
			{
				this->listarFuncionarios();
				break;
			}

		}
	}
	this->endAnimais();
	this->endFuncionarios();
}