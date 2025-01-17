#ifndef UTILS_H
#define UTILS_H

// Função para verificar se um arquivo existe
int arquivo_existe(const char *nome_arquivo);

// Função para validar se um identificador EAN-8 é válido
int validar_identificador(const char *identificador);

// Função para gerar uma imagem PBM baseada em um identificador
void gerar_imagem_pbm_identificador(const char *identificador, int largura, int altura, const char *nome_arquivo);

// Função para extrair o identificador do código de barras em um arquivo PBM
int extrair_identificador_pbm(const char *nome_arquivo, char *identificador);

#endif
