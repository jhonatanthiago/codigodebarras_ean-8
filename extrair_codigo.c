#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo.pbm>\n", argv[0]);
        return 1;
    }

    const char *nome_arquivo = argv[1];

    // Verificar se o arquivo existe
    if (!arquivo_existe(nome_arquivo)) {
        printf("Erro: arquivo %s nao encontrado ou corrompido.\n", nome_arquivo);
        return 1;
    }

    // Extrair o identificador do arquivo PBM
    char identificador[9] = {0}; // Espaço para 8 dígitos + nulo
    if (!extrair_identificador_pbm(nome_arquivo, identificador)) {
        printf("Erro: codigo de barras nao encontrado na imagem.\n");
        return 1;
    }

    printf("Identificador extraido: %s\n", identificador);
    return 0;
}
