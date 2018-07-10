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
					if(dadosLinha[13] == "true")
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
					if(dadosLinha[11] == "true")
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

	for(auto it = this->mapaAnimais.begin(); it != this->mapaAnimais.end(); ++it)
	{
    	cout << it->first << " " << it->second << endl;
	}

	Animais.close();
}