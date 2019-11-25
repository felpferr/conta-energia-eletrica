#ifndef HISTORICO_H
#define HISTORICO_H
#include <string>
#include <vector>

using namespace std;

class historico{
public:
	historico();
	
	int setData(string);
	int setConsumo(string);
	int setDiaRegitro(string);
	int setMedia(string);

	const vector<string> getMesAno();
	const vector<int> getConsumo();
	const vector<int> getdiaRegistro();
	const vector<double> getMedia();

private:
	vector<int> consumo, dia_registro;
	vector<double> mediaKwhDia;
	vector<string> mesAno;
};

#endif // !HISTORICO_H

