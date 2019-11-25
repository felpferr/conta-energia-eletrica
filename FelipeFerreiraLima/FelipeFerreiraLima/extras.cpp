#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "valoresFaturados.h"
#include "arquivoBinario.h"
#include "arquivoTexto.h"
#include "consumo.h"
#include "historico.h"
#include "extras.h"

using namespace std;

int inicio(int argc, char *argv[]){
	ArquivoBinario ab;
	ArquivoTexto at;
	vector<string> parametros;
	int acao = verificaParametros(argc, argv, parametros);
	parametros.shrink_to_fit();

	switch (acao){
		case 1:
			importarArquivo(at,parametros);
			break;

		default:
			break;
	}

	return 0;
}

/*Essa função verifica os parâmetros passados por linha de comando e atribui os valores para um vector.
	retorna 1 caso tenha que importar apenas um arquivo;
	retorna 2 caso tenha que importar arquivos de um diretório;
	retorna 3 caso sejam passados como parâmetro [numeroInstalação] || <dataAtual> ||  <dataInicial> <dataFinal>.
*/
int verificaParametros(int argc, char *argv[], vector<string> &parametros){
	string str = argv[argc-1];
	
	if (argc > 4 || argc <= 1) {
		return help();
	}

	if (str.find(".pdf", 0) != string::npos) {
		if (argc > 2) {
			str = argv[1];
			for (int i = 2; i < argc; i++) {
				str.append(" ");
				str.append(argv[i]);
			}
			parametros.push_back(str);
			return 1;
		}
		else {
			parametros.push_back(argv[1]);
			return 1;
		}
	}
	else {
		str = argv[1];
		if (str.find("Faturas Cemig",0) != string::npos) {
			parametros.push_back(argv[1]);
			///Executar a função de importar pelo diretório.
			/*string comando;
			comando = "cd ";
			comando.append(argv[1]);
			system(comando.c_str);*/
			return 2;
		}
		else {
			for (int i = 1; i < argc; i++) {
				parametros.push_back(argv[i]);
			}
			return 3;
		}
	}
}

vector<string> split(string str, char delimitador){
	vector<string> vector;
	stringstream stream(str);
	string token;

	while (getline(stream, token, delimitador))
		vector.push_back(token);

	return vector;
}

int help(){
	cout << "cee.exe [ArquivoConta.pdf] || [DiretorioDeContas]\n\
			   || [NumeroInstalacao] || <Mes/Ano atual>\n\
			   || <Mes/Ano inicial> <Mes/Ano final>" << endl;
	return 0;
}

int importarArquivo(ArquivoTexto &at, vector<string> &parametros) {
	converteArquivoPdf(parametros);
	vector<string> tokens = split(parametros[parametros.size()-1],'.');
	string nomeArquivoTxt = tokens[0];

	nomeArquivoTxt.append(".txt");

	cout << nomeArquivoTxt;

	return 1;
}

int converteArquivoPdf(vector<string> &parametros){
	char comando[460]; 
	
	sprintf_s(comando,"%s%s","pdftotext.exe -table -fixed 5 -marginl 0 ",parametros[parametros.size()-1].c_str());
	system(comando);

	return 1;
}
