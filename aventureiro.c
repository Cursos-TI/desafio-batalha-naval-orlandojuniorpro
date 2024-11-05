/* Como Jogar?
Visualização: O tabuleiro será exibido antes de cada ataque.
Fazendo um Ataque: Insira as coordenadas na forma de dois números inteiros:

Digite as coordenadas do ataque (linha coluna): 

Feedback: O programa informará se você acertou um navio, se foi água ou se já atacou a posição.
Finalizando o Jogo: O jogo termina quando todos os segmentos dos navios são afundados.
Dicas Adicionais
Lembre-se das posições que você já atacou.
Tente atacar áreas adjacentes após um acerto.
Com essas instruções e a nova implementação, você agora tem um jogo de Batalha Naval interativo e expandido! Divirta-se jogando! */

#include <stdio.h>
#include <stdbool.h>

#define LINHAS 10
#define COLUNAS 10

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    printf("\nTabuleiro Atual:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (tabuleiro[i][j] == 3) {
                printf("N "); // N para navio
            } else if (tabuleiro[i][j] == 1) {
                printf("X "); // X para ataque bem-sucedido
            } else if (tabuleiro[i][j] == -1) {
                printf("O "); // O para ataque falho
            } else {
                printf(". "); // . para casa vazia
            }
        }
        printf("\n");
    }
}

// Função principal
int main() {
    int tabuleiro[LINHAS][COLUNAS] = {0}; // Inicializa o tabuleiro com zeros

    // Declaração das coordenadas para os navios
    const int NAVIO_HORIZONTAL_X = 2; // Posição X do navio horizontal
    const int NAVIO_HORIZONTAL_Y = 3; // Posição Y do navio horizontal
    const int NAVIO_VERTICAL_X = 5;   // Posição X do navio vertical
    const int NAVIO_VERTICAL_Y = 1;    // Posição Y do navio vertical

    // Posicionando o navio horizontal (4 partes)
    for (int i = 0; i < 4; i++) {
        tabuleiro[NAVIO_HORIZONTAL_X][NAVIO_HORIZONTAL_Y + i] = 3;
        printf("Parte do navio horizontal posicionado na casa [%d][%d]\n", NAVIO_HORIZONTAL_X, NAVIO_HORIZONTAL_Y + i);
    }

    // Posicionando o navio vertical (3 partes)
    for (int i = 0; i < 3; i++) {
        tabuleiro[NAVIO_VERTICAL_X + i][NAVIO_VERTICAL_Y] = 3;
        printf("Parte do navio vertical posicionado na casa [%d][%d]\n", NAVIO_VERTICAL_X + i, NAVIO_VERTICAL_Y);
    }

    // Posicionando um navio diagonal (3 partes)
    for (int i = 0; i < 3; i++) {
        tabuleiro[7 + i][2 + i] = 3;
        printf("Parte do navio diagonal posicionado na casa [%d][%d]\n", 7 + i, 2 + i);
    }

    // Posicionando outro navio diagonal (2 partes)
    for (int i = 0; i < 2; i++) {
        tabuleiro[1 + i][8 - i] = 3;
        printf("Parte do navio diagonal posicionado na casa [%d][%d]\n", 1 + i, 8 - i);
    }

    // Jogo de Batalha Naval
    int tentativas = 0;
    int acertos = 0;
    bool jogoAtivo = true;

    while (jogoAtivo) {
        int ataqueX, ataqueY;

        exibirTabuleiro(tabuleiro); // Exibe o tabuleiro antes do ataque

        // Solicita ao usuário as coordenadas do ataque
        printf("Digite as coordenadas do ataque (linha coluna): ");
        scanf("%d %d", &ataqueX, &ataqueY);

        // Verifica se as coordenadas estão dentro dos limites do tabuleiro
        if (ataqueX < 0 || ataqueX >= LINHAS || ataqueY < 0 || ataqueY >= COLUNAS) {
            printf("Coordenadas inválidas! Tente novamente.\n");
            continue;
        }

        // Processa o ataque
        tentativas++;
        if (tabuleiro[ataqueX][ataqueY] == 3) { // Acertou um navio
            printf("Acertou!\n");
            tabuleiro[ataqueX][ataqueY] = 1; // Marca como ataque bem-sucedido
            acertos++;
        } else if (tabuleiro[ataqueX][ataqueY] == 0) { // Casa vazia
            printf("Água!\n");
            tabuleiro[ataqueX][ataqueY] = -1; // Marca como ataque falho
        } else {
            printf("Você já atacou essa posição!\n");
        }

        // Verifica se todos os navios foram afundados
        if (acertos == 12) { // Total de partes dos navios: 4 + 3 + 3 + 2 = 12
            jogoAtivo = false;
            printf("Parabéns! Você afundou todos os navios em %d tentativas!\n", tentativas);
        }
    }

    return 0;
}