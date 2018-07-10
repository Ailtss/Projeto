#include "PetFera.h"

PetFera::PetFera()
{

}

void PetFera::init()
{
	Tratador tres(26, "Ramos da Silva", "070931384-54", 22, "O", '-', "Répteis");
	Veterinario dois(13, "Figueira Dantas","070931384-54", 20, "A", '+', "Aves");
	ifstream Animais("data/animais.csv");
	vector<string> dadosLinha;
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
			if(dadosLinha[1] == "Mammalia")
			{
				if(dadosLinha[13] != "")
				{
					int aux = stoi(dadosLinha[0]);
					shared_ptr<Animal> m = make_shared<MamiferoNativo>(stoi(dadosLinha[0]), dadosLinha[1], dadosLinha[2], dadosLinha[3], *(dadosLinha[4].c_str()), stof(dadosLinha[5]),
					dadosLinha[6], dois, tres, dadosLinha[9], dadosLinha[10], dadosLinha[11], dadosLinha[12], dadosLinha[13]);
					this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(aux, m));
				}
				else
				{
					int aux = stoi(dadosLinha[0]);
					shared_ptr<Animal> m = make_shared<MamiferoExotico>(stoi(dadosLinha[0]), dadosLinha[1], dadosLinha[2], dadosLinha[3], *(dadosLinha[4].c_str()), stof(dadosLinha[5]),
					dadosLinha[6], dois, tres, dadosLinha[9], dadosLinha[10], dadosLinha[11], dadosLinha[12]);
					this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(aux, m));
				}
			}
			else if(dadosLinha[1] == "Aves")
			{
				if(dadosLinha[14] != "")
				{
					int aux = stoi(dadosLinha[0]);
					shared_ptr<Animal> m = make_shared<AveNativa>(stoi(dadosLinha[0]), dadosLinha[1], dadosLinha[2], dadosLinha[3], *(dadosLinha[4].c_str()), stof(dadosLinha[5]),
					dadosLinha[6], dois, tres, dadosLinha[9], stoi(dadosLinha[10]), stoi(dadosLinha[11]), dadosLinha[12], dadosLinha[13], dadosLinha[14]);
					this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(aux, m));
				}
				else
				{
					int aux = stoi(dadosLinha[0]);
					shared_ptr<Animal> m = make_shared<AveExotica>(stoi(dadosLinha[0]), dadosLinha[1], dadosLinha[2], dadosLinha[3], *(dadosLinha[4].c_str()), stof(dadosLinha[5]),
					dadosLinha[6], dois, tres, dadosLinha[9], stoi(dadosLinha[10]), stoi(dadosLinha[11]), dadosLinha[12], dadosLinha[13]);
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
					dadosLinha[6], dois, tres, dadosLinha[9], venenoso, dadosLinha[11], dadosLinha[12], dadosLinha[13], dadosLinha[14]);
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
					dadosLinha[6], dois, tres, dadosLinha[9], venenoso, dadosLinha[11], dadosLinha[12], dadosLinha[13]);
					this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(aux, m));
				}
			}
			else if(dadosLinha[1] == "Amphibia")
			{
				if(dadosLinha[14] != "")
				{
					int aux = stoi(dadosLinha[0]);
					shared_ptr<Animal> m = make_shared<AnfibioNativo>(stoi(dadosLinha[0]), dadosLinha[1], dadosLinha[2], dadosLinha[3], *(dadosLinha[4].c_str()), stof(dadosLinha[5]),
					dadosLinha[6], dois, tres, dadosLinha[9], stoi(dadosLinha[10]), dadosLinha[11], dadosLinha[12], dadosLinha[13], dadosLinha[14]);
					this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(aux, m));
				}
				else
				{
					int aux = stoi(dadosLinha[0]);
					shared_ptr<Animal> m = make_shared<AnfibioExotico>(stoi(dadosLinha[0]), dadosLinha[1], dadosLinha[2], dadosLinha[3], *(dadosLinha[4].c_str()), stof(dadosLinha[5]),
					dadosLinha[6], dois, tres, dadosLinha[9], stoi(dadosLinha[10]), dadosLinha[11], dadosLinha[12], dadosLinha[13]);
					this->mapaAnimais.insert(pair<int, shared_ptr<Animal>>(aux, m));
				}
			}
			dadosLinha.clear();
		}
	}
	for(auto it = this->mapaAnimais.begin(); it != this->mapaAnimais.end(); ++it)
	{
    	cout << it->first << " " << it->second << endl;
	}
	ifstream mapaFuncionarios("data/funcionarios.csv");
}