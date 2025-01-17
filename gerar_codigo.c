#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int main(int argc, char *argv[]) {
    // Verificação de argumentos na linha de comando
    if (argc < 2) {
        printf("Uso: %s <identificador> [espacamento] [pixels por area] [altura] [arquivo.pbm]\n", argv[0]);
        printf("Valores padrao serao usados caso nao sejam fornecidos argumentos.\n");
    }

    const char *identificador = argv[1];

    // Argumentos opcionais com valores padrão
    int espacamento = (argc > 2) ? atoi(argv[2]) : 10;
    int pixels_por_area = (argc > 3) ? atoi(argv[3]) : 10;
    int altura = (argc > 4) ? atoi(argv[4]) : 50;
    const char *nome_arquivo = (argc > 5) ? argv[5] : "codigo.pbm";

    if (!validar_identificador(identificador)) {
        printf("Erro: identificador invalido.\n");
        return 1;
    }

    // Verificar se o arquivo já existe
    if (arquivo_existe(nome_arquivo)) {
        char resposta;
        printf("O arquivo %s ja existe. Deseja sobrescreve ele? (s/n): ", nome_arquivo);
        scanf(" %c", &resposta);
        if (resposta != 's' && resposta != 'S') {
            printf("Erro: arquivo resultante ja existe.\n");
            return 1;
        }
    }

    // Gerar a imagem PBM
    gerar_imagem_pbm_identificador(identificador, espacamento * 8, altura, nome_arquivo);
    return 0;
}
