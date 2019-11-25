#include <iostream>
#include <cstring>
#include "arquivoTexto.h"

// Fecha o arquivo texto antes do objeto ser removido da mem�ria.
ArquivoTexto::~ArquivoTexto() {
	fechar();
}

/* Abre um arquivo texto identificado pelo par�metro nomeArquivo.
* O modo de abertura do arquivo deve ser especificado por uma das constantes de TipoDeAcesso.
* Se o arquivo n�o existir ele ser� criado. Se o modo for ESCRITA e o arquivo j� existir em disco,
* todo o seu conte�do ser� exclu�do.
* Retorna true se o arquivo foi aberto com sucesso e false caso contr�rio.
*/
bool ArquivoTexto::abrir(string nomeArquivo, TipoDeAcesso modo) {
	this->nomeArquivo = nomeArquivo;

	// Abre o arquivo segundo o modo de abertura.
	switch (modo) {
	case ACRESCENTAR: outputFile.open(nomeArquivo, ios::app);
		if (outputFile.is_open()) return true;
		break;

	case ESCRITA: outputFile.open(nomeArquivo, ios::out);
		if (outputFile.is_open()) return true;
		break;

	case LEITURA: inputFile.open(nomeArquivo, ios::in);
		/* O teste abaixo verifica se foi retornado um ponteiro v�lido, diferente de nulo, se sim o teste � true indicando que o arquivo foi aberto com sucesso.
		Caso contr�rio, um ponteiro nulo indica que houve erro ao tentar abrir o arquivo.
		*/
		if (inputFile) return true;
	}
	return false;
} // abrir()

  /* Escreve no arquivo texto o conte�do do objeto string armazenado no par�metro conteudo.
  * A escrita do conteudo sempre ocorre no fim do arquivo.
  * Retorna true se a opera��o foi realizada com sucesso e false caso contr�rio.
  */
bool ArquivoTexto::escrever(string conteudo) {
	/* Escreve no arquivo se ele estiver aberto.
	* Posiciona o ponteiro de posi��o de arquivo no fim e escreve o conte�do.
	*/
	if (outputFile.is_open()) {
		outputFile.seekp(0, ios::end);
		outputFile << conteudo << endl;
		return true;
	}
	return false;
} // escrever()

  /* L� o conte�do do arquivo texto.
  * Retorna um objeto string com todo o conte�do do arquivo texto.
  * Em caso de erro retorna um objeto string com o valor literal "NULL".
  */
string ArquivoTexto::ler() {
	char linha[TAMANHO_LINHA];

	// Verifica se ocorreu erro ao acessar o arquivo.
	if (!inputFile) return "NULL";

	// L� o conte�do do arquivo at� atingir o fim do arquivo.
	do { // L� o conte�do de uma linha limitada a TAMANHO_LINHA caracteres ou at� encontrar o caractere nova linha ('\n'). 
		inputFile.getline(linha, TAMANHO_LINHA);

		// Verifica se atingiu o fim do arquivo. Se n�o, armazena as linhas lidas do texto em um objeto string.
		if (!inputFile.eof()) {
			texto.append(linha);
			texto.append("\n");
		}
	} while (!inputFile.eof());
	return texto;
} // ler()

  /* L� o conte�do de uma linha de texto do arquivo identificada por numeroLinha.
  * A primeira linha de texto � de n�mero zero (0).
  * Retorna um objeto string com o conte�do da linha de texto.
  * Em caso de erro retorna um objeto string com o valor literal "NULL".
  *
  * ATEN��O: Este m�todo s� ir� recuperar a linha de texto correta do arquivo se todas
  *          as linhas de texto possu�rem o mesmo tamanho (comprimento), em bytes.
  */
string ArquivoTexto::lerLinha(int numeroLinha) {
	char linha[TAMANHO_LINHA];

	// Verifica se ocorreu erro ao acessar o arquivo.
	if (!inputFile) return "NULL";

	// L� o conte�do do arquivo at� atingir o fim do arquivo.
	if (numeroLinha >= 0) {
		inputFile.seekg(numeroLinha);
		inputFile.getline(linha, TAMANHO_LINHA);
	}
	return linha;
} // lerLinha()

  // Fecha o arquivo texto.
void ArquivoTexto::fechar() {
	// Fecha o arquivo se estiver aberto.
	if (inputFile.is_open()) inputFile.close();
	if (outputFile.is_open()) outputFile.close();
	texto.clear();
}

// Obt�m o nome do arquivo texto.
string ArquivoTexto::getNomeArquivo() {
	return nomeArquivo;
}