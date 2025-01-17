# **Projeto EAN-8 - Geração e Extração de Códigos de Barras**

## **Síntese do Projeto**

Este projeto tem como objetivo implementar duas ferramentas para manipulação de códigos de barras no formato EAN-8. A primeira ferramenta, chamada **gerar_codigo**, gera uma imagem de código de barras a partir de um identificador EAN-8 válido, enquanto a segunda, **extrair_codigo**, realiza a extração do identificador EAN-8 de um arquivo de imagem PBM contendo o código de barras.

A geração do código de barras é feita a partir de um identificador de 8 dígitos numéricos, validando se o identificador está correto antes de gerar a imagem. O identificador gerado pode ser ajustado com argumentos adicionais, como o espaçamento, a altura da imagem e a quantidade de pixels por área do código.

A extração do código de barras, por sua vez, funciona analisando arquivos de imagem no formato PBM, verificando a integridade do arquivo e extraindo o identificador correspondente.

O projeto foi desenvolvido utilizando a linguagem **C** e pode ser facilmente compilado e executado a partir do terminal. Todos os testes para verificar o funcionamento correto da geração e extração dos códigos de barras foram realizados e descritos abaixo.

---

# **Passo 1: Compilação do Código**

Para compilar os programas, utilize os seguintes comandos no terminal:

```bash
gcc -o gerar_codigo gerar_codigo.c utils.c
gcc -o extrair_codigo extrair_codigo.c utils.c
```

- O primeiro comando compila o programa que gera a imagem do código de barras.
- O segundo comando compila o programa que extrai o identificador a partir do código de barras em formato PBM.

---

# **Passo 2: Testes de Geração de Código de Barras**

### **TESTE 1: Gerar código com identificador válido**

Com um identificador EAN-8 válido, como "12345670", o programa gerará um arquivo PBM com o código de barras:

```bash
./gerar_codigo 12345670 codigo1.pbm
```

- **Resultado Esperado:** O arquivo `codigo1.pbm` será criado na pasta atual, contendo o código de barras correspondente ao identificador "12345670".

### **TESTE 2: Gerar código com identificador inválido (menos de 8 dígitos)**

O identificador fornecido tem menos de 8 dígitos. O programa deve apresentar uma mensagem de erro:

```bash
./gerar_codigo 1234567 codigo2.pbm
```

- **Resultado Esperado:** O programa exibirá uma mensagem de erro informando que o identificador deve ter 8 dígitos.

### **TESTE 3: Gerar código com identificador inválido (não numérico)**

O identificador contém caracteres não numéricos. O programa deve rejeitar a entrada e informar um erro:

```bash
./gerar_codigo 123A5670 codigo3.pbm
```

- **Resultado Esperado:** O programa exibirá uma mensagem de erro indicando que o identificador contém caracteres não numéricos.

### **TESTE 4: Geração com Argumentos Opcionais**

Você pode passar argumentos opcionais para ajustar o espaçamento, a altura e os pixels por área. O seguinte comando irá gerar um código de barras com valores personalizados:

```bash
./gerar_codigo 12345670 15 10 100 codigo_custom.pbm
```

- **Resultado Esperado:** O arquivo `codigo_custom.pbm` será gerado com as configurações de espaçamento, altura e pixels por área especificados.

---

# **Passo 3: Testes de Extração de Código de Barras**

### **TESTE 1: Extração de Identificador a Partir de Arquivo Válido**

Com um arquivo PBM válido contendo um código de barras, o programa irá extrair o identificador EAN-8:

```bash
./extrair_codigo codigo.pbm
```

- **Resultado Esperado:** O programa exibirá o identificador EAN-8 extraído da imagem contida no arquivo `codigo.pbm`.

### **TESTE 2: Extração de Identificador de Arquivo Inexistente**

Se você tentar extrair um identificador de um arquivo que não existe, o programa mostrará uma mensagem de erro:

```bash
./extrair_codigo arquivo_inexistente.pbm
```

- **Resultado Esperado:** O programa informará que o arquivo `arquivo_inexistente.pbm` não foi encontrado.

### **TESTE 3: Extração com Arquivo Inválido (Não PBM ou Corrompido)**

Caso o arquivo PBM esteja corrompido ou não seja um arquivo válido, o programa exibirá uma mensagem de erro:

```bash
./extrair_codigo arquivo_corrompido.pbm
```

- **Resultado Esperado:** O programa mostrará uma mensagem informando que o arquivo não é válido ou está corrompido.

---

# **Conclusão**

Este projeto foi desenvolvido para validar, gerar e extrair códigos de barras EAN-8 a partir de arquivos de imagem PBM. A execução é simples e os testes cobrem casos comuns de uso, incluindo identificadores válidos e inválidos, e manipulação de arquivos válidos e corrompidos. Ao utilizar os testes de geração e extração descritos, podemos garantir o correto funcionamento da aplicação.
