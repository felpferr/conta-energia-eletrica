#include <iostream>
#include "arquivoBinario.h"

/* Abre o arquivo com o nome especificado em nomeArquivo para escrita e leitura de dados.
* Se o arquivo n�o existir ele ser� criado.
* Retorna true se o arquivo foi aberto com sucesso e false caso contr�rio.
*/
bool ArquivoBinario::abrir(string nomeArquivo) {
	this->nomeArquivo = nomeArquivo;

	// Abre o arquivo bin�rio para escrita (acrescenta toda sa�da no fim do arquivo) e leitura de dados.
	arquivoBinario.open(nomeArquivo, ios::app | ios::in | ios::binary);

	if (arquivoBinario) return true;
	return false;
}

// Fecha o arquivo.
void ArquivoBinario::fechar() {
	if (arquivoBinario.is_open()) arquivoBinario.close();
}

// Obt�m a refer�ncia do arquivoBinario.
fstream& ArquivoBinario::getArquivoBinario() {
	return arquivoBinario;
}

// Obt�m o nome do arquivo.
string ArquivoBinario::getNomeArquivo() {
	return nomeArquivo;
}

// Obt�m o tamanho do arquivo em bytes.
unsigned long ArquivoBinario::tamanhoArquivo() {
	// Obt�m a posi��o inicial do arquivo.
	arquivoBinario.seekp(0, ios::beg);
	unsigned long inicio = static_cast<unsigned long>(arquivoBinario.tellp());

	// Obt�m a posi��o final do arquivo.
	arquivoBinario.seekp(0, ios::end);
	unsigned long fim = static_cast<unsigned long>(arquivoBinario.tellp());

	// Calcula o tamanho do arquivo.
	return fim - inicio;
}