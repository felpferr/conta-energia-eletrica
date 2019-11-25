#ifndef EXTRAS_H
#define EXTRAS_H
#include <string>
#include <vector>
#include "arquivoTexto.h"

using namespace std;

int inicio(int, char*[]);
int verificaParametros(int, char *[], vector<string>&);
vector<string> split(string, char);
int help();
int importarArquivo(ArquivoTexto &, vector<string> &);
int converteArquivoPdf(vector<string> &);

#endif // !EXTRAS_H

