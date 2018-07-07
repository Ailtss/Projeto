#include <iostream>
#include <fstream>
#include <map>
#include <memory>
#include <vector>
using namespace std;
#include "anfibio.h"
#include "mamifero.h"
#include "reptil.h"
#include "aveNativa.h"
#include "aveExotica.h"

void consultarAnimal(string key)
{

	if(key == "Mammalia" || key == "Reptilia" || key = "Aves" || key == "Amphibia")
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

void RemoveFuncionario(int id)
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

void RemoveAnimal(int id)
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


void cadastrarTrat(Tratador t)
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

void cadastrarVet(Veterinario v)
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


int main(int argc, char const *argv[])
{

	Tratador tres(26, "Ramos da Silva", "070931384-54", 22, 1, '-', "Répteis");
	Veterinario dois(13, "Figueira Dantas","070931384-54", 20, 0, '+', "Aves");

	cadastrarTrat(tres);
	cadastrarVet(dois);

/*
	map<int, unique_ptr<Animal>> mapaAnimais;
	map<int, unique_ptr<Funcionario>> mapaFuncionarios;
	ifstream animais, funcionarios;
	animais.open("animais.csv");
	funcionarios.open("funcionarios.csv");
	if(animais.bad() || funcionarios.bad())
	{
		cerr << "Os arquivos não abriram corretamente!" << endl;
	}

		string id;
		string tipo;
		string nome;
		string cpf;
		string idade;
		string tipo_sanguineo;
		string fatorRH;
		string especialidade;
		int _id;
		short _idade;
		const char *c_tipo_sanguineo;
		const char *c_fatorRH;


	while(!funcionarios.eof())
	{
		

		getline(funcionarios, id, ';');
		getline(funcionarios, tipo, ';');
		getline(funcionarios, nome, ';');
		getline(funcionarios, cpf, ';');
		getline(funcionarios, idade, ';');
		getline(funcionarios, tipo_sanguineo, ';');
		getline(funcionarios, fatorRH, ';');
		getline(funcionarios, especialidade, ';');
		_id = atoi(id.c_str());
		_idade = stoi(idade);
		c_tipo_sanguineo = tipo_sanguineo.c_str();
		c_fatorRH = fatorRH.c_str();
	}

	if(tipo == "Tratador")
	{
		Tratador um(_id, nome, cpf, _idade, *c_tipo_sanguineo, *c_fatorRH, especialidade);
		um.impress();
	}
	*/




/*	while(!animais.eof())
	{
	
		string id;
		string classe;
		string nome;
		string nomeCient;
		string sexo;
		string tamanho;
		string dieta;
		string vet;
		string trat;
		string batismo;
		string corPelo;

		getline(animais, id, ';');
		getline(animais, classe, ';');
		getline(animais, nome, ';');
		getline(animais, nomeCient, ';');
		getline(animais, sexo, ';');
		getline(animais, tamanho, ';');
		getline(animais, dieta, ';');
		getline(animais, vet, ';');
		getline(animais, trat, ';');
		getline(animais, batismo, ';');
		getline(animais, corPelo, ';');
		int _id = atoi(id.c_str());
		float _tamanho = atof(tamanho.c_str());
		const char *_sexo = sexo.c_str();
	}
*/









/*	cout << "Testando classe Funcionário: " << endl;
	cout << endl;
	cout << endl;

	Funcionario um(13, "Ailton Gabriel","070931384-54", 20, 0, '+');

	um.impress();

	cout << "Testando classe Veterinário: " << endl;
	cout << endl;
	cout << endl;

	Veterinario dois(13, "Figueira Dantas","070931384-54", 20, 0, '+', "Aves");

	Tratador tres(26, "Ramos da Silva", "070931384-54", 22, 1, '-', "Répteis");

	//dois.impress();

	//tres.impress();

	Ave teste(15, "Mammalia", "Leão", "Panthera Leo", 'M', 2, "Carne", dois, tres, "Simba", 10, 15);

	teste.impress();
*/
	
	//animais.close();
	//funcionarios.close();
	return 0;
}