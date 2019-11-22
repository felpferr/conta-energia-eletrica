#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <vector>

using namespace std;

class cliente{
public:
	cliente();
	
	int setNome(string);
	int setEndereço(string);
	int setNumeroInstalacao(string);

	const string getNome();
	const string getEndereco();
	const vector<long int> getNumeroInstalacao();
	int getQuantidadeInstalacaoes();

private:
	string nome, endereco;
	int quantidade_instalacoes;
	vector<long int> numero_instalacao;
};

#endif // !CLIENTE_H

