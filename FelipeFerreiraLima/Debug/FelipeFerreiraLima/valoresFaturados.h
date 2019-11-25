#ifndef VALORESFATURADOS_H
#define VALORESFATURADOS_H
#include <string>

using namespace std;

class valoresFaturados
{
public:
	valoresFaturados();

	int setPrecoEnergiaEletrica(string);
	int setValorContribuicaoIluminacao(string);
	int setBandeiraAmarela(string);
	int setBandeiraVermelha(string);

	double getPrecoEnergiaEletrica();
	double getValorContribuicaoIluminacao();
	double getBandeiraAmarela();
	double getBandeiraVermelha();

private:
	double precoEnergiaEletrica, valorContribuicaoIluminacao, 
		   bandeiraAmarela, bandeiraVermelha;
};

#endif // !VALORESFATURADOS_H

