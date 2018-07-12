#include "PetFera.h"

PetFera::PetFera()
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

			cout << linha.str() << endl;
			
			if(dadosLinha[1] == "Tratador")
			{

				int aux = stoi(dadosLinha[0]);
				short idade = stoi(dadosLinha[3]);

				shared_ptr<Tratador> f = make_shared<Tratador>(aux, dadosLinha[1], dadosLinha[2], idade, dadosLinha[4], *(dadosLinha[5].c_str()), dadosLinha[6]);
				this->mapaTratadores.insert(pair<int, shared_ptr<Tratador>>(aux, f));
			}

			else
			{
				int aux = stoi(dadosLinha[0]);
				short idade = stoi(dadosLinha[3]);

				shared_ptr<Veterinario> f = make_shared<Veterinario>(aux, dadosLinha[1], dadosLinha[2], idade, dadosLinha[4], *(dadosLinha[5].c_str()), dadosLinha[6]);
				this->mapaVeterinarios.insert(pair<int, shared_ptr<Veterinario>>(aux, f));
			}

			dadosLinha.clear();
		}
	}

	else
	{
		cerr << "Arquivo de Funcionários não foi aberto corretamente!" << endl;
	}

	for(auto it = this->mapaTratadores.begin(); it != this->mapaTratadores.end(); ++it)
	{
    	cout << it->first << " " << it->second << endl;
	}

	for(auto it = this->mapaVeterinarios.begin(); it != this->mapaVeterinarios.end(); ++it)
	{
    	cout << it->first << " " << it->second << endl;
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
			cout << linha.str() << endl;
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

	shared_ptr<Animal> print;

	for(auto it = this->mapaAnimais.begin(); it != this->mapaAnimais.end(); ++it)
	{
		print = it->second;
    	cout << it->first << endl;
    	cout << *print << endl;
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

	for(auto it = this->mapaAnimais.begin(); it != this->mapaAnimais.end(); ++it)
	{
		print = it->second;
    	cout << it->first << " " << *print << endl;
	}
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

	for(auto it = this->mapaAnimais.begin(); it != this->mapaAnimais.end(); ++it)
	{
		print = it->second;
    	cout << it->first << " " << *print << endl;
	}
}

void PetFera::consultarAnimal()
{
	string consulta;
	bool achou = false;
	cout << "Digite o id do animal ou a sua classe: ";
	getline(cin, consulta);
	if(consulta == "Mammalia" || consulta == "Aves" || consulta == "Amphibia" || consulta = "Reptilia")
	{
		for(auto it = mapaAnimais.begin(); it != mapaAnimais.end(); it++)
		{
			if(it->second->getAnClasse() == consulta)
			{
				cout << *(it->second);
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
		for(auto it = mapaAnimais.begin(); it != mapaAnimais.end(); it++)
		{
			if(it->second->getAnId() == idProcurado)
			{
				cout << *(it->second);
				achou = true;
			}
		}
		if(achou == false)
		{
			cout << "Animal não encontrado no sistema..." << endl;
		}
	}
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
			for(auto it = this->mapaAnimais.begin(); it != this->mapaAnimais.end(); ++it)
			{
				print = it->second;
    			cout << it->first << " " << *print << endl;
			}
			return true;
		}
	}
	cout << "Animal não foi encontrado no sistema, tente novamente..." << endl;
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