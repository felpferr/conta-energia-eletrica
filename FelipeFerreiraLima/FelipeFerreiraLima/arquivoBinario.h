#ifndef ARQUIVO_BINARIO
#define ARQUIVO_BINARIO

#include <fstream>
#include <string>

using namespace std;

class ArquivoBinario {
public:
	/* Abre o arquivo com o nome especificado em nomeArquivo para escrita e leitura de dados.
	* Se o arquivo n�o existir ele ser� criado.
	* Retorna true se o arquivo foi aberto com sucesso e false caso contr�rio.
	*/
	bool abrir(string nomeArquivo);

	// Fecha o arquivo.
	void fechar();

	// Obt�m o nome do arquivo.
	string getNomeArquivo();

	// Obt�m a refer�ncia do arquivoBinario.
	fstream& getArquivoBinario();

	// Obt�m o tamanho do arquivo em bytes.
	unsigned long tamanhoArquivo();

private:
	string nomeArquivo;
	fstream arquivoBinario; // Arquivo bin�rio para escrita e leitura de dados. 
};
#endif