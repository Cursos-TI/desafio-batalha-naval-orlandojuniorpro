/* Como Jogar
Visualização do Tabuleiro: O tabuleiro será exibido no console antes de cada ataque. As posições dos navios são marcadas como N, as casas vazias como ., os acertos como X e os erros como O.
Fazendo um Ataque:
O programa solicitará que você insira as coordenadas do ataque na forma de dois números inteiros: a linha e a coluna.
As coordenadas devem estar dentro dos limites do tabuleiro, que é uma matriz de 5x5 (0 a 4 para linhas e colunas).
Por exemplo, para atacar a posição na primeira linha e terceira coluna, você deve digitar:

0 2

Feedback do Ataque:
Após cada ataque, o programa informará se você acertou um navio (Acertou!), se foi água (Água!) ou se já atacou aquela posição anteriormente (Você já atacou essa posição!).
Finalizando o Jogo:
O jogo continua até que todos os segmentos dos navios sejam afundados.
Quando isso acontecer, uma mensagem de vitória será exibida informando quantas tentativas você levou para afundar todos os navios.
Dicas
Tente lembrar quais posições você já atacou para evitar ataques repetidos.
Use uma estratégia para escolher suas coordenadas de ataque, como atacar áreas adjacentes após um acerto.
Exemplo de Jogo
O tabuleiro inicial pode parecer assim:

Tabuleiro Atual:
. . . . .
. N N . .
. . . . .
N . . . .
N . . . .

Você insere as coordenadas:

Digite as coordenadas do ataque (linha coluna): 1 2

Se você acertar um navio, verá:

Acertou!

O tabuleiro será atualizado e exibido novamente.
Continue atacando até afundar todos os navios!
Seguindo essas instruções, você poderá jogar Batalha Naval utilizando o código fornecido de forma interativa e divertida! */


#include <stdio.h>
#include <stdbool.h>

#define LINHAS 5
#define COLUNAS 5

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
    const int NAVIO_HORIZONTAL_X = 1; // Posição X do navio horizontal
    const int NAVIO_HORIZONTAL_Y = 2; // Posição Y do navio horizontal
    const int NAVIO_VERTICAL_X = 3;   // Posição X do navio vertical
    const int NAVIO_VERTICAL_Y = 1;    // Posição Y do navio vertical

    // Posicionando o navio horizontal (2 partes)
    for (int i = 0; i < 2; i++) {
        tabuleiro[NAVIO_HORIZONTAL_X][NAVIO_HORIZONTAL_Y + i] = 3;
        printf("Parte do navio horizontal posicionado na casa [%d][%d]\n", NAVIO_HORIZONTAL_X, NAVIO_HORIZONTAL_Y + i);
    }

    // Posicionando o navio vertical (3 partes)
    for (int i = 0; i < 3; i++) {
        tabuleiro[NAVIO_VERTICAL_X + i][NAVIO_VERTICAL_Y] = 3;
        printf("Parte do navio vertical posicionado na casa [%d][%d]\n", NAVIO_VERTICAL_X + i, NAVIO_VERTICAL_Y);
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
        if (acertos == 5) { // Total de partes dos navios: 2 + 3 = 5
            jogoAtivo = false;
            printf("Parabéns! Você afundou todos os navios em %d tentativas!\n", tentativas);
        }
    }

    return 0;
}