#include "historico.h"

historico::historico(){
}

int historico::setData(string data){
	mesAno.push_back(data);
	return 1;
}

int historico::setConsumo(string consumo){
	this->consumo.push_back(stoi(consumo));
	return 1;
}

int historico::setDiaRegitro(string dia_registro){
	this->dia_registro.push_back(stoi(dia_registro));
	return 1;
}

int historico::setMedia(string mediaKwhDia){
	this->mediaKwhDia.push_back(stod(mediaKwhDia));
	return 1;
}



const vector<string> historico::getMesAno(){	
	return mesAno;
}

const vector<int> historico::getConsumo(){
	return consumo;
}

const vector<int> historico::getdiaRegistro(){
	return dia_registro;
}

const vector<double> historico::getMedia(){
	return mediaKwhDia;
}
