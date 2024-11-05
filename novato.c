/* Como Jogar?
Visualização do Tabuleiro:
Após iniciar o jogo, o tabuleiro será exibido. As posições são representadas da seguinte forma:
0: Espaço vazio (não atacado)
.: Parte do navio (não visível para o jogador)
X: Acerto (parte do navio atingida)
O: Erro (posição vazia atingida)
Fazendo um Ataque:
O jogador deve inserir as coordenadas para atacar uma posição no tabuleiro.
As coordenadas devem ser digitadas no formato "linha coluna" (por exemplo, 3 4), onde:
O primeiro número representa a linha (0 a 9).
O segundo número representa a coluna (0 a 9).
Exemplo de Entrada:
Para atacar a posição na linha 2 e coluna 3, você deve digitar:

2 3

Resultados do Ataque:
Após inserir as coordenadas, o jogo informará se você acertou ou errou.
Se você acertar uma parte do navio, essa posição será marcada como X.
Se você errar, a posição será marcada como O.
Repetição de Tentativas:
O jogo continuará solicitando novas coordenadas até que todas as partes dos navios sejam afundadas.
Se você tentar atacar uma posição já atacada anteriormente, receberá uma mensagem informando que já atacou essa posição.
Condições de Vitória:
O jogo termina quando você acerta todas as partes dos navios (totalizando 10 acertos).
Uma mensagem de vitória será exibida parabenizando você por afundar todos os navios.
Dicas para Jogar
Estratégia: Tente atacar áreas que parecem mais prováveis de conter navios, como grupos de posições adjacentes.
Registro de Tentativas: Mantenha um registro mental ou em papel das suas tentativas para evitar repetir ataques em posições já atacadas.
Encerramento
Após vencer ou decidir encerrar o jogo, você pode fechar a janela do terminal ou pressionar Ctrl+C para interromper a execução.
Com essas instruções, você deve estar pronto para jogar Batalha Naval! Divirta-se e boa sorte na sua busca por afundar todos os navios!

  */

#include <stdio.h>

#define TAMANHO 10 // Tamanho do tabuleiro

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // Inicializa todas as posições com 0
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 3) {
                printf(". "); // Não exibe partes do navio
            } else if (tabuleiro[i][j] == 1) {
                printf("X "); // Acerto
            } else if (tabuleiro[i][j] == -1) {
                printf("O "); // Erro
            } else {
                printf("0 "); // Espaço vazio
            }
        }
        printf("\n");
    }
}

// Função para posicionar navios
void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO]) {
    // Posicionamento dos navios
    // Navio horizontal
    int navioHorizontalX = 2;
    int navioHorizontalY = 3;
    int tamanhoNavioHorizontal = 3;

    // Navio vertical
    int navioVerticalX = 5;
    int navioVerticalY = 6;
    int tamanhoNavioVertical = 4;

    // Navio diagonal (de cima para baixo)
    int navioDiagonalX1 = 1;
    int navioDiagonalY1 = 1;
    int tamanhoNavioDiagonal1 = 3;

    // Navio diagonal (de baixo para cima)
    int navioDiagonalX2 = 8;
    int navioDiagonalY2 = 3;
    int tamanhoNavioDiagonal2 = 3;

    // Posicionando o navio horizontal
    for (int i = 0; i < tamanhoNavioHorizontal; i++) {
        tabuleiro[navioHorizontalX][navioHorizontalY + i] = 3;
    }

    // Posicionando o navio vertical
    for (int i = 0; i < tamanhoNavioVertical; i++) {
        tabuleiro[navioVerticalX + i][navioVerticalY] = 3;
    }

    // Posicionando o navio diagonal de cima para baixo
    for (int i = 0; i < tamanhoNavioDiagonal1; i++) {
        tabuleiro[navioDiagonalX1 + i][navioDiagonalY1 + i] = 3;
    }

    // Posicionando o navio diagonal de baixo para cima
    for (int i = 0; i < tamanhoNavioDiagonal2; i++) {
        tabuleiro[navioDiagonalX2 - i][navioDiagonalY2] = 3;
    }
}

// Função principal
int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    
    inicializarTabuleiro(tabuleiro); // Inicializa o tabuleiro
    posicionarNavios(tabuleiro);      // Posiciona os navios

    int tentativas = 0;
    int acertos = 0;

    while (acertos < 10) { // O jogador precisa acertar todas as partes dos navios
        exibirTabuleiro(tabuleiro); // Exibe o estado atual do tabuleiro
        
        int x, y;
        printf("Digite as coordenadas para atacar (linha coluna): ");
        scanf("%d %d", &x, &y);

        // Verifica se as coordenadas estão dentro do tabuleiro
        if (x < 0 || x >= TAMANHO || y < 0 || y >= TAMANHO) {
            printf("Coordenadas inválidas! Tente novamente.\n");
            continue;
        }

        // Verifica se já foi atacado antes
        if (tabuleiro[x][y] == 1 || tabuleiro[x][y] == -1) {
            printf("Você já atacou essa posição! Tente novamente.\n");
            continue;
        }

        tentativas++;

        // Verifica se houve acerto ou erro
        if (tabuleiro[x][y] == 3) { // Parte do navio
            printf("Acertou!\n");
            tabuleiro[x][y] = 1; // Marca como acerto
            acertos++;
        } else { // Espaço vazio ou erro
            printf("Errou!\n");
            tabuleiro[x][y] = -1; // Marca como erro
        }
        
        printf("Tentativas: %d | Acertos: %d\n", tentativas, acertos);
        
        if (acertos == 10) { // Se o jogador acertar todas as partes dos navios
            printf("Parabéns! Você afundou todos os navios!\n");
        }
    }

    return 0;
}