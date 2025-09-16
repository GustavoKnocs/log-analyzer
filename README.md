# 🔍 Analisador de Logs de Segurança em C++

Um programa simples em **C++** que lê arquivos de log do sistema (como `auth.log`) e gera um relatório com a contagem de tentativas de login falhas por endereço de IP.

## 📋 Funcionalidades

-   Procura por tentativas de login mal-sucedidas (`Failed password`).
-   Extrai e contabiliza os IPs responsáveis.
-   Mostra os resultados ordenados pelo número de tentativas.

## 🚀 Como Executar

### 1. Clone o repositório

```bash
git clone https://github.com/SEU-USUARIO/log-analyzer.git
cd log-analyzer
```

### 2. Compile o programa

```bash
g++ -o analisador analyzer.cpp -std=c++11
```

### 3. Execute

```bash
./analisador
```

> **Nota:** Por padrão, o programa lê o arquivo `auth.log` na mesma pasta. Se quiser, você pode editar o código para analisar outro arquivo de log.


## 🖥️ Demonstração

Abaixo, um exemplo da saída do programa ao analisar um arquivo de log de exemplo:

![Resultado da Execução](screenshots/execution-result.png)

---

## 🔧 Tecnologias Utilizadas

-   C++
-   g++
-   Linux / WSL (Ubuntu)

## 📌 Sobre

*Projeto criado para estudo e prática de análise de logs em segurança da informação.*
