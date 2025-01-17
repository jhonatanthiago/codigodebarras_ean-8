#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para verificar se um arquivo existe
int arquivo_existe(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo) {
        fclose(arquivo);
        return 1; // Arquivo existe
    }
    return 0; // Arquivo não existe
}

// Função para validar se um identificador EAN-8 é numérico
int validar_identificador(const char *identificador) {
    if (strlen(identificador) != 8) {
        return 0; // Identificador deve ter exatamente 8 dígitos
    }

    for (int i = 0; i < 8; i++) {
        if (identificador[i] < '0' || identificador[i] > '9') {
            return 0; // Contém caracteres não numéricos
        }
    }

    // Validação do dígito verificador
    int soma_pares = 0, soma_impares = 0;
    for (int i = 0; i < 7; i++) {
        int digito = identificador[i] - '0';
        if (i % 2 == 0) { // Posições ímpares (começando de 0)
            soma_impares += digito;
        } else { // Posições pares
            soma_pares += digito;
        }
    }

    soma_impares *= 3;
    int soma_total = soma_pares + soma_impares;
    int digito_verificador = (10 - (soma_total % 10)) % 10;

    return (identificador[7] - '0') == digito_verificador;
}

// Função para gerar uma imagem PBM baseada em um identificador
void gerar_imagem_pbm_identificador(const char *identificador, int largura, int altura, const char *nome_arquivo) {
    if (!validar_identificador(identificador)) {
        printf("Erro: identificador invalido.\n");
        return;
    }

    FILE *arquivo = fopen(nome_arquivo, "w");
    if (!arquivo) {
        printf("Erro: nao foi possivel criar o arquivo %s.\n", nome_arquivo);
        return;
    }

    // Cabeçalho PBM
    fprintf(arquivo, "P1\n");
    fprintf(arquivo, "%d %d\n", largura, altura);

    // Ajuste da largura do módulo para garantir que a proporção da imagem seja correta
    int largura_modulo = largura / (8 * 7); // Cada dígito do EAN-8 tem 7 módulos
    int altura_modulo = altura / 2; // Ajuste da altura para que a imagem tenha proporções mais adequadas

    // Geração do código de barras
    for (int y = 0; y < altura; y++) {
        for (int x = 0; x < largura; x++) {
            int digito_atual = (x / (7 * largura_modulo)) % 8; // Qual dígito está sendo representado
            int modulo = (x / largura_modulo) % 7; // Posição dentro do padrão de 7 módulos
            int valor = (identificador[digito_atual] - '0') & (1 << (6 - modulo)); // Lê o bit específico

            fprintf(arquivo, "%d ", valor ? 1 : 0); // 1 = Preto, 0 = Branco
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Imagem gerada com sucesso: %s\n", nome_arquivo);
}

// Função para extrair o identificador do código de barras em um arquivo PBM
int extrair_identificador_pbm(const char *nome_arquivo, char *identificador) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        return 0; // Não conseguiu abrir o arquivo
    }

    // Leitura do cabeçalho PBM
    char tipo[3];
    fscanf(arquivo, "%s", tipo);  // Lê o tipo de imagem, deve ser "P1"
    if (strcmp(tipo, "P1") != 0) {
        fclose(arquivo);
        return 0; // Formato inválido
    }

    // Ignora a linha de dimensões (largura e altura)
    int largura, altura;
    fscanf(arquivo, "%d %d", &largura, &altura);
    
    // Simulação de extração de dados
    for (int i = 0; i < 8; i++) {
        identificador[i] = '0' + i; // Preenchendo o identificador com valores fictícios
    }
    identificador[8] = '\0'; // Termina a string

    fclose(arquivo);
    return 1; // Sucesso
}
