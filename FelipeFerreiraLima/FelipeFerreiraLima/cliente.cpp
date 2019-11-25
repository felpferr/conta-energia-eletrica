#include "cliente.h"

cliente::cliente(){
	nome = "";
	endereco = "";
	quantidade_instalacoes = 0;
}

int cliente::setNome(string nomeCliente){
	nome = nomeCliente;
	return 1;
}

int cliente::setEndereço(string endereco){
	this->endereco = endereco;
	return 1;
}

int cliente::setNumeroInstalacao(string numero_instalacao){
	this->numero_instalacao.push_back(stol(numero_instalacao.c_str()));
	return 1;
}

const string cliente::getNome(){
	return nome;
}

const string cliente::getEndereco(){
	return endereco;
}

const vector<long int> cliente::getNumeroInstalacao(){
	return numero_instalacao;
}

int cliente::getQuantidadeInstalacaoes(){
	return quantidade_instalacoes;
}

