#include <iostream> // Para entrada e saída (cout)
#include <fstream>  // Para manipulação de arquivos (ifstream)
#include <string>   // Para usar a classe string
#include <map>      // Para usar a estrutura de dados map (dicionário)
#include <vector>   // Para usar vetores
#include <algorithm>// Para usar funções de ordenação (sort)

// Função auxiliar para ordenar o mapa por valor (contagem)
bool compararPares(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    return a.second > b.second;
}

int main() {
    std::string nomeArquivo = "auth.log";
    std::ifstream arquivo(nomeArquivo); // Abre o arquivo para leitura

    if (!arquivo.is_open()) {
        std::cerr << "Erro: Nao foi possivel abrir o arquivo " << nomeArquivo << std::endl;
        return 1; // Retorna um código de erro
    }

    std::map<std::string, int> contagemIPs; // Mapa para armazenar: [IP, contagem]
    std::string linha;
    std::string palavraChave = "Failed password";

    // Lê o arquivo linha por linha
    while (std::getline(arquivo, linha)) {
        // Procura a palavra-chave na linha
        size_t pos = linha.find(palavraChave);
        if (pos != std::string::npos) { // Se a palavra-chave for encontrada
            // Procura a palavra "from" para encontrar o IP
            size_t fromPos = linha.find("from ", pos);
            if (fromPos != std::string::npos) {
                // O IP começa depois de "from "
                size_t ipStart = fromPos + 5;
                // Procura o próximo espaço para delimitar o fim do IP
                size_t ipEnd = linha.find(" ", ipStart);
                
                // Extrai a substring do IP
                std::string ip = linha.substr(ipStart, ipEnd - ipStart);
                
                // Incrementa a contagem para este IP no mapa
                contagemIPs[ip]++;
            }
        }
    }

    arquivo.close(); 

    // --- Geração do Relatório ---
    std::cout << "====== Relatorio de Analise de Log ======" << std::endl;
    std::cout << "Contagem de tentativas de login falhas por IP:" << std::endl;

    // Para ordenar, copiamos o mapa para um vetor de pares
    std::vector<std::pair<std::string, int>> ipsOrdenados(contagemIPs.begin(), contagemIPs.end());
    std::sort(ipsOrdenados.begin(), ipsOrdenados.end(), compararPares);

    // Imprime os IPs e suas contagens, já ordenados
    for (const auto& par : ipsOrdenados) {
        std::cout << "- IP: " << par.first << "\t| Tentativas: " << par.second << std::endl;
    }

    return 0; 
}
