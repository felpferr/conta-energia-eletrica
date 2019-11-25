#include "consumo.h"

consumo::consumo(){
	mesConsumo = 0;
	valorPagar = 0.0;
}

int consumo::setMesConsumo(string mesConsumo){
	this->mesConsumo = stoi(mesConsumo);
	return 1;
}

int consumo::setDataVencimento(string dataVencimento){
	this->dataVencimento = dataVencimento;
	return 1;
}

int consumo::setValorPagar(string valorPagar){
	this->valorPagar = stod(valorPagar);
	return 1;
}

int consumo::setConsumoKwt(string consumoKwh){
	this->consumoKwh = stoi(consumoKwh);
	return 1;
}

int consumo::getMesConsumo(){
	return mesConsumo;
}

const string consumo::getDataVencimento(){
	return dataVencimento;
}

double consumo::getValorPagar(){
	return valorPagar;
}
