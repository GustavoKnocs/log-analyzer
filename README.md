# Analisador de Logs de Segurança em C++

Um programa simples em C++ que lê um arquivo de log, encontra tentativas de login falhas e gera um relatório com a contagem por endereço de IP.

## Demonstração

![Resultado da Execução](screenshots/resultado_execucao.png)

## Tecnologias

- C++ 
- Compilador g++
- Ambiente Linux / WSL (Ubuntu)

## Como Executar

No seu terminal Linux ou WSL, siga os passos:

```bash
# 1. Clone este repositório
git clone [https://github.com/SEU-USUARIO/log-analyzer.git](https://github.com/SEU-USUARIO/log-analyzer.git)

# 2. Entre no diretório
cd analisador-cognyte

# 3. Compile o programa
g++ -o analisador analisador.cpp -std=c++11

# 4. Execute
./analisador
```
