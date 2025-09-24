#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <regex>

// Função para ordenar contagens em ordem decrescente
bool compararPares(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    return a.second > b.second;
}

int main(int argc, char* argv[]) {
    std::string nomeArquivo = (argc > 1) ? argv[1] : "auth.log";
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro: Não foi possível abrir o arquivo " << nomeArquivo << std::endl;
        return 1;
    }

    std::unordered_map<std::string, int> contagemIPs;
    std::string linha;

    // Procura por linhas que contenham "sshd" e alguma variação de "fail" ou "invalid"
    std::regex regexFiltro(R"(sshd.*([fF]ail|[iI]nvalid))");

    // Procura por um padrão de IPv4 OU um padrão de IPv6
    std::regex regexIP(R"((\b\d{1,3}(\.\d{1,3}){3}\b)|(\b([0-9a-fA-F]{0,4}:){2,7}[0-9a-fA-F]{0,4}\b))");

    while (std::getline(arquivo, linha)) {
        // Usa a regex de filtro
        if (std::regex_search(linha, regexFiltro)) {
            std::smatch match;

            // Procura por qualquer IP (IPv4 ou IPv6) na linha filtrada
            if (std::regex_search(linha, match, regexIP)) {
                contagemIPs[match.str(0)]++;
            }
        }
    }

    arquivo.close();

    // --- Relatório ---
    std::cout << "====== Relatório de Análise de Log ======" << std::endl;
    std::cout << "Tentativas de login falhas por IP:" << std::endl;

    if (contagemIPs.empty()) {
        std::cout << "Nenhum IP encontrado nas linhas de log com falha." << std::endl;
    } else {
        std::vector<std::pair<std::string, int>> ipsOrdenados(contagemIPs.begin(), contagemIPs.end());
        std::sort(ipsOrdenados.begin(), ipsOrdenados.end(), compararPares);

        for (const auto& par : ipsOrdenados) {
            std::cout << "- IP: " << par.first << "\t| Tentativas: " << par.second << std::endl;
        }
    }

    return 0;
}