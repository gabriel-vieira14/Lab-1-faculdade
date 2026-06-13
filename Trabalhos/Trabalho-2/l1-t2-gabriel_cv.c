#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
void preenche_vetor(int vetor[16]) {
    for(int i = 0; i < 16; i++) {
        vetor[i] = i;
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
int busca_indice(int vetor[16], int n) {
    for(int i = 0; i < 16; i++) {
        if(vetor[i] == n) {
            return i; 
        }
    }
    return -1;
}
bool verifica_ordem(int vetor[16]) {
    for(int i = 0; i < 16; i++) {
        if(vetor[i] != i) {
            return false;
        }
    }
    return true;
}
void move_esquerda(int vetor[16]) {
    int indice_15 = busca_indice(vetor, 15);
    if (indice_15 % 4 != 0) {
        int indice_alvo = indice_15 - 1; 
        int temp = vetor[indice_alvo];  
        
        vetor[indice_alvo] = 15;        
        vetor[indice_15] = temp;       
    }
}
void move_cima(int vetor[16]) {
    int indice_15 = busca_indice(vetor, 15);
    if (indice_15 >= 4) {
        int indice_alvo = indice_15 - 4; 
        int temp = vetor[indice_alvo];   
        
        vetor[indice_alvo] = 15;         
        vetor[indice_15] = temp;         
    }
}
void move_direita(int vetor[16]) {
    int indice_15 = busca_indice(vetor, 15);
    if (indice_15 % 4 != 3) {
        int indice_alvo = indice_15 + 1; 
        int temp = vetor[indice_alvo];   
        
        vetor[indice_alvo] = 15;         
        vetor[indice_15] = temp;         
    }
}
void move_baixo(int vetor[16]) {
    int indice_15 = busca_indice(vetor, 15);
    if (indice_15 <= 11) {
        int indice_alvo = indice_15 + 4; 
        int temp = vetor[indice_alvo];   
        
        vetor[indice_alvo] = 15;         
        vetor[indice_15] = temp;         
    }
}
void movimento_aleatorio(int vetor[16]) {
    int sorteio = rand() % 4;
    switch (sorteio) {
        case 0:
            move_esquerda(vetor);
            break; 
        case 1:
            move_direita(vetor);
            break;
        case 2:
            move_cima(vetor);
            break;
        case 3:
            move_baixo(vetor);
            break;
    }
}
void embaralha_vetor(int vetor[16]) {
    for (int i = 0; i < 400; i++) {
        movimento_aleatorio(vetor);
    }
}
void anda(int vetor[16], char tecla) {
    if(tecla == 'w' || tecla == 'c' || tecla == 'A') {
        move_baixo(vetor);
    } else if (tecla == 'a' || tecla == 'e' || tecla == 'D') {
        move_direita(vetor); 
    } else if (tecla == 's' || tecla == 'b' || tecla == 'B') {
        move_cima(vetor);
    } else if (tecla == 'd' || tecla == 'C') {
        move_esquerda(vetor);
    }
}
void move_peca_posicao(int vetor[16], int pos) {
    if (pos >= 0 && pos <= 15) {
        int indice_15 = busca_indice(vetor, 15);
        
        if (pos == indice_15 - 1) {
            move_esquerda(vetor);
        } else if (pos == indice_15 + 1) {
            move_direita(vetor);
        } else if (pos == indice_15 - 4) {
            move_cima(vetor);
        } else if (pos == indice_15 + 4) {
            move_baixo(vetor);
        }
    }
}
void cor_letra(int r, int g, int b) { printf("%c[38;2;%d;%d;%dm", 27, r, g, b); }
void cor_fundo(int r, int g, int b) { printf("%c[48;2;%d;%d;%dm", 27, r, g, b); }
void cor_normal() { printf("%c[0m", 27); }
void cor_tabuleiro() { cor_fundo(140, 70, 20); }
void cor_peca() { cor_fundo(200, 200, 170); cor_letra(70, 50, 40); }
void cor_vazio() { cor_fundo(0, 0, 0); }

void pula_linha() {
    printf("\r\n");
}

void limpa_tela() {
    cor_normal();
    printf("%c[2J", 27); // limpa a tela
    printf("%c[H", 27);  // põe o cursor no início
}

void desenha_borda() {
    cor_normal();
    printf("%3s", "");
    cor_tabuleiro();
    printf("%32s","");
    cor_normal();
    pula_linha();
}

void imprime_pedaco_linha_v8(int t[], int l, bool com_peca) {
    char desenho[] = "ABCDEFGHIJKLMNO ";
    cor_normal();
    printf("%3s", "");
    cor_tabuleiro();
    printf("  ");
    for (int i = 0; i < 4; i++) {
        int v = t[l*4 + i];
        v == 15 ? cor_vazio() : cor_peca();
        printf("   %c   ", com_peca ? desenho[v] : ' ');
    }
    cor_tabuleiro();
    printf("  ");
    cor_normal();
    pula_linha();
}

void imprime_linha_v8(int t[], int l) {
    imprime_pedaco_linha_v8(t, l, false);
    imprime_pedaco_linha_v8(t, l, true);
    imprime_pedaco_linha_v8(t, l, false);
}

void imprime_tabuleiro_v8(int t[]) {
    limpa_tela();
    pula_linha();
    desenha_borda();
    for (int linha = 0; linha < 4; linha++) {
        imprime_linha_v8(t, linha);
    }
    desenha_borda();
    printf("\r\nUse W,A,S,D ou setas para mover. Pressione Q para sair.\r\n");
}
int main() {
    srand(time(NULL));
    int vetor[16];
    char tecla = ' ';
    preenche_vetor(vetor);
    embaralha_vetor(vetor);
    system("stty raw -echo");
    while(verifica_ordem(vetor) == false && (tecla != 'Q' && tecla != 'q')) {
        imprime_tabuleiro_v8(vetor);
        tecla = getchar();
        anda(vetor, tecla);
    }
    imprime_tabuleiro_v8(vetor);
    system("stty sane");
    if (verifica_ordem(vetor) == true) {
        printf("\nParabéns! Voce resolveu o quebra-cabecas!\n");
    } else {
        printf("\nJogo encerrado pelo jogador.\n");
    }
    fflush(stdout);
    return 0;
}