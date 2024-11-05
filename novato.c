/* Como jogar o jogo?  

No jogo de Batalha Naval, as coordenadas que o usuário deve digitar para jogar
geralmente seguem um formato de par ordenado, onde um número representa
a linha (eixo Y) e uma letra representa a coluna (eixo X). Aqui estão os
detalhes sobre como as coordenadas são utilizadas:
Formato das Coordenadas: O jogador informa uma coordenada ao adversário
usando o formato "LetraNúmero". Por exemplo, "A1", "B3", ou "C5".
A letra corresponde à coluna e o número à linha do tabuleiro.
Exemplo de Entrada: Se um jogador deseja atacar a posição na
primeira linha e na primeira coluna, ele deve digitar "A1".
Para a terceira linha e segunda coluna, o jogador deve digitar "B3".
Respostas do Adversário: Após informar a coordenada, o adversário
responde com "água" se não houver navio naquela posição
ou "acertou um..." se uma parte do navio for atingida127.
Regras de Jogo: Cada jogador normalmente tem um número
limitado de tentativas por rodada, como três tiros,
e deve registrar suas tentativas para evitar repetir os mesmos ataques.  */

#include <stdio.h>
#include <stdlib.h>

#define LINHAS 10
#define COLUNAS 10

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 0; // Inicializa todas as posições com 0
        }
    }
}

// Função para posicionar os navios
void posicionarNavios(int tabuleiro[LINHAS][COLUNAS]) {
    // Navio horizontal
    int navioHorizontalX = 2;
    int navioHorizontalY = 3;
    int tamanhoNavioHorizontal = 3;

    // Navio vertical
    int navioVerticalX = 5;
    int navioVerticalY = 6;
    int tamanhoNavioVertical = 4;

    // Posicionando o navio horizontal no tabuleiro
    for (int i = 0; i < tamanhoNavioHorizontal; i++) {
        tabuleiro[navioHorizontalX][navioHorizontalY + i] = 3;
    }

    // Posicionando o navio vertical no tabuleiro
    for (int i = 0; i < tamanhoNavioVertical; i++) {
        tabuleiro[navioVerticalX + i][navioVerticalY] = 3;
    }
}

// Função para exibir o estado atual do tabuleiro
void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(". "); // Espaço vazio
            } else if (tabuleiro[i][j] == 1) {
                printf("X "); // Acerto
            } else if (tabuleiro[i][j] == -1) {
                printf("O "); // Erro
            } else {
                printf("? "); // Parte do navio (não exibido ao jogador)
            }
        }
        printf("\n");
    }
}

// Função principal
int main() {
    int tabuleiro[LINHAS][COLUNAS];
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    int tentativas = 0;
    int acertos = 0;

    while (acertos < 7) { // O jogador precisa acertar todas as partes dos navios
        exibirTabuleiro(tabuleiro);
        
        int x, y;
        printf("Digite as coordenadas para atacar (linha coluna): ");
        scanf("%d %d", &x, &y);

        // Verifica se as coordenadas estão dentro do tabuleiro
        if (x < 0 || x >= LINHAS || y < 0 || y >= COLUNAS) {
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
        } else { // Espaço vazio
            printf("Errou!\n");
            tabuleiro[x][y] = -1; // Marca como erro
        }
        
        printf("Tentativas: %d | Acertos: %d\n", tentativas, acertos);
    }

    printf("Parabéns! Você afundou todos os navios!\n");
    
    return 0;
}