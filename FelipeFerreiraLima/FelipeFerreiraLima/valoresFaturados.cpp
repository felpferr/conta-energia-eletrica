#include "valoresFaturados.h"

valoresFaturados::valoresFaturados(){
	precoEnergiaEletrica = 0.0;
	valorContribuicaoIluminacao = 0.0;
	bandeiraAmarela = -1.1;
	bandeiraVermelha = -1.1;
}

int valoresFaturados::setPrecoEnergiaEletrica(string precoEnergiaEletrica){
	this->precoEnergiaEletrica = stod(precoEnergiaEletrica);
	return 1;
}

int valoresFaturados::setValorContribuicaoIluminacao(string valorContribuicaoIluminacao){
	this->valorContribuicaoIluminacao = stod(valorContribuicaoIluminacao);
	return 1;
}

int valoresFaturados::setBandeiraAmarela(string bandeiraAmarela){
	bandeiraAmarela == "Não Possui" ? this->bandeiraAmarela = -1 : this->bandeiraAmarela = stod(bandeiraAmarela);
	return 1;
}

int valoresFaturados::setBandeiraVermelha(string bandeiraVermelha){
	bandeiraVermelha == "Nao Possui" ? this->bandeiraVermelha = -1 : this->bandeiraVermelha = stod(bandeiraVermelha);
	return 1;
}

double valoresFaturados::getPrecoEnergiaEletrica(){
	return precoEnergiaEletrica;
}

double valoresFaturados::getValorContribuicaoIluminacao(){
	return valorContribuicaoIluminacao;
}

double valoresFaturados::getBandeiraAmarela(){
	return bandeiraAmarela;
}

double valoresFaturados::getBandeiraVermelha(){
	return bandeiraVermelha;
}
