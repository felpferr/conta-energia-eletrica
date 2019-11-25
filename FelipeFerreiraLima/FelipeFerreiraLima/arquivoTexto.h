#ifndef ARQUIVOTEXTO_H
#define ARQUIVOTEXTO_H

#include <fstream>
#include <string>

using namespace std;

/* Define os tipos de acesso que podem ser usados para acessar o arquivo. Os modos dispon�veis s�o:

ACRESCENTAR: abre o arquivo somente para acrescentar dados no fim do arquivo;
ESCRITA: abre o arquivo somente para a escrita de dados;
LEITURA: abre o arquivo somente para a leitura de seu conte�do.
*/
enum TipoDeAcesso { ACRESCENTAR, ESCRITA, LEITURA };

#define TAMANHO_LINHA 380

class ArquivoTexto {
public:
	// Fecha o arquivo texto antes do objeto ser removido da mem�ria.
	~ArquivoTexto();

	/* Abre um arquivo texto identificado pelo par�metro nomeArquivo.
	* O modo de abertura do arquivo deve ser especificado por uma das constantes de TipoDeAcesso.
	* Se o arquivo n�o existir ele ser� criado. Se o modo for ESCRITA e o arquivo j� existir em disco,
	* todo o seu conte�do ser� exclu�do.
	* Retorna true se o arquivo foi aberto com sucesso e false caso contr�rio.
	*/
	bool abrir(string nomeArquivo, TipoDeAcesso modo);

	/* Escreve no arquivo texto o conte�do do objeto string armazenado no par�metro conteudo.
	* A escrita sempre ocorre no fim do arquivo.
	* Retorna true se a opera��o foi realizada com sucesso e false caso contr�rio.
	*/
	bool escrever(string conteudo);

	/* L� o conte�do do arquivo texto.
	* Retorna um objeto string com todo o conte�do do arquivo texto.
	* Em caso de erro retorna um objeto string com o valor literal "NULL".
	*/
	string ler();

	/* L� o conte�do de uma linha de texto do arquivo identificada por numeroLinha.
	* A primeira linha de texto � de n�mero zero (0).
	* Retorna um objeto string com o conte�do da linha de texto.
	* Em caso de erro retorna um objeto string com o valor literal "NULL".
	*
	* ATEN��O: Este m�todo s� ir� recuperar a linha de texto correta do arquivo se todas
	*          as linhas de texto possu�rem o mesmo tamanho (comprimento), em bytes.
	*/
	string lerLinha(int numeroLinha);

	// Fecha o arquivo texto.
	void fechar();

	// Obt�m o nome do arquivo texto.
	string getNomeArquivo();

private:
	string nomeArquivo, texto;
	ifstream inputFile;
	ofstream outputFile;
};

#endif // !ARQUIVOTEXTO

