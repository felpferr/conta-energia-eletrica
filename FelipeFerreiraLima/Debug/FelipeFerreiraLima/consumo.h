#ifndef CONSUMO_H
#define CONSUMO_H
#include <vector>
#include <string>

using namespace std;

class consumo{
public:
	consumo();

	int setMesConsumo(string);
	int setDataVencimento(string);
	int setValorPagar(string);
	int setConsumoKwt(string);

	int getMesConsumo();
	const string getDataVencimento();
	double getValorPagar();

private:
	int mesConsumo,consumoKwh;
	string dataVencimento;
	double valorPagar;
};


#endif // !CONSUMO_H

