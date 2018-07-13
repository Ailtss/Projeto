#ifndef PETFERA_H
#define PETFERA_H
#include <memory>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "animalSilvestre.h"
#include "mamiferoNativo.h"
#include "mamiferoExotico.h"
#include "aveExotica.h"
#include "aveNativa.h"
#include "anfibioExotico.h"
#include "anfibioNativo.h"
#include "reptilExotico.h"
#include "reptilNativo.h"
using namespace std;

#include "animal.h"
#include "funcionario.h"

/**@brief Classe PetFera que utiliza todos código para tornar mais "limpo" e legível o funcionamento no main.cpp*/
class PetFera
{
protected:
	/**@brief Mapa que utiliza chaves inteiras e valores sendo objetos da classe Animal*/
	map<int, shared_ptr<Animal>> mapaAnimais; 
	/**@brief Mapa que utiliza chaves inteiras e valores sendo objetos da classe Veterinario*/
	map<int, shared_ptr<Veterinario>> mapaVeterinarios; 
	/**@brief Mapa que utiliza chaves inteiras e valores sendo objetos da classe Tratadores*/
	map<int, shared_ptr<Tratador>> mapaTratadores; 
public:
	PetFera();
	~PetFera();
	void clearScreen();
	/**@brief Inicializa os mapas a partir dos dados contidos no arquivo*/
	void init(); 
	/**@brief Cadastra um Animal do tipo Nativo no mapa*/
	void cadastrarAnimalNativo();
	/**@brief Cadastra um Animal do tipo Exótico no mapa*/ 
	void cadastrarAnimalExotico(); 
	/**@brief Cadastra um Veterinário no mapa*/
	void cadastrarVeterinario();
	/**@brief Cadastra um Tratador no mapa*/
	void cadastrarTratador(); 
	/**@brief Faz uma consulta no mapa de Animais*/
	void consultarAnimal(); 
	/**@brief Faz uma consulta no mapa de Funcionários*/
	void consultarPorFuncionario(); 
	/**@brief Remove um animal do mapa*/
	bool removerAnimal(); 
	/**@brief Remove um Funcionário do Mapa*/
	bool removerFuncionario(); 
	/**@brief Passa o animais do mapa para seu respectivo arquivo*/
	void endAnimais(); 
	/**@brief Passa os funcionários do mapa para seu respectivo arquivo*/
	void endFuncionarios(); 
	/**@brief Lista os animais existentes*/
	void listarAnimais();
	/**@brief Lista os Funcionários existentes*/
	void listarFuncionarios(); 
	/**@brief Método para gerar uma interface para o usuário*/
	void menu(); 
};

#endif