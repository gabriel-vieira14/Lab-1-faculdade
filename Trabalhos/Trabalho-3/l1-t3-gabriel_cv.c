#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tela.h" 

typedef enum {
    MODO_PRINCIPAL,
    MODO_EDICAO_TEXTO,
    MODO_EDICAO_COR,
    MODO_EDICAO_ETIQUETA,
    MODO_EDICAO_TEXTO_BUSCA, 
    MODO_EDICAO_ETIQUETA_BUSCA,
    MODO_TERMINAR
} ModoOperacao;

typedef struct {
    int red;
    int green;
    int blue;
} Cor;

typedef struct {
    int x_inicial, y_inicial, tam_x, tam_y;
} Retangulo;

typedef struct {
    char etiqueta[4]; 
    Cor cor_retangulo;
    Retangulo tam_retangulo;
    char texto[101];  
} Nota;

typedef struct {
    Nota *vetor_notas; 
    int quantidade;
    int capacidade;
    ModoOperacao modo_atual;
    int indice_nota_corrente;
    int cursor_x;
    int cursor_y;
    Nota ultima_removida;
    int tem_removida; 
    char texto_edicao[101]; 
    int cursor_texto;
    Cor cor_edicao;
    int comp_cor_selecionado;
    char etiqueta_edicao[4]; 
    int cursor_etiqueta;

    char texto_busca[101]; 
    int cursor_texto_busca;
    char etiqueta_busca[4]; 
} GerenciadorApp;

void inicializa_e_le_arquivo(GerenciadorApp *app, const char *nome_arquivo) {
    app->texto_busca[0] = '\0';
    app->cursor_texto_busca = 0;
    app->etiqueta_busca[0] = '\0';
    app->quantidade = 0;
    app->capacidade = 10; 
    app->vetor_notas = malloc(app->capacidade * sizeof(Nota));
    app->modo_atual = MODO_PRINCIPAL;
    app->indice_nota_corrente = 0;
    app->cursor_x = 10; 
    app->cursor_y = 10;

    FILE *arq = fopen(nome_arquivo, "r");
    if (arq == NULL) return;

    Nota n;
    while (fscanf(arq, " %3s %d %d %d %d %d %d %d \"%100[^\"]\"%*[^\n]",
                  n.etiqueta, &n.cor_retangulo.red, &n.cor_retangulo.green, &n.cor_retangulo.blue,
                  &n.tam_retangulo.x_inicial, &n.tam_retangulo.y_inicial, &n.tam_retangulo.tam_x, &n.tam_retangulo.tam_y, n.texto) == 9) {
        
        if (app->quantidade >= app->capacidade) {
            app->capacidade *= 2; 
            app->vetor_notas = realloc(app->vetor_notas, app->capacidade * sizeof(Nota));
        }
        app->vetor_notas[app->quantidade] = n;
        app->quantidade++;
    }
    fclose(arq);
}

void desenha_nota(Nota n) {
    int larg_tela, alt_tela;
    t_tamanho(&larg_tela, &alt_tela);
    if (n.tam_retangulo.x_inicial > larg_tela || n.tam_retangulo.y_inicial > alt_tela) return;
    int tam_x_visivel = n.tam_retangulo.tam_x;
    if (n.tam_retangulo.x_inicial + n.tam_retangulo.tam_x - 1 > larg_tela) {
        tam_x_visivel = larg_tela - n.tam_retangulo.x_inicial + 1;
    }
    t_corfundo(n.cor_retangulo.red, n.cor_retangulo.green, n.cor_retangulo.blue);
    int media_cor = (n.cor_retangulo.red + n.cor_retangulo.green + n.cor_retangulo.blue) / 3;
    if (media_cor < 120) {
        t_cortexto(255, 255, 255); 
    } else {
        t_cortexto(0, 0, 0);
    }
    for (int i = 0; i < n.tam_retangulo.tam_y; i++) {
        int linha_atual = n.tam_retangulo.y_inicial + i;
        if (linha_atual > alt_tela) break; 
        
        t_lincol(linha_atual, n.tam_retangulo.x_inicial);
        printf("%*s", tam_x_visivel, "");
    }
    t_lincol(n.tam_retangulo.y_inicial, n.tam_retangulo.x_inicial);
    printf("%.*s", tam_x_visivel < 3 ? tam_x_visivel : 3, n.etiqueta);
    int len_texto = strlen(n.texto);
    int altura_util = n.tam_retangulo.tam_y - 1; 
    int char_idx = 0; 
    
    for (int i = 0; i < altura_util && char_idx < len_texto; i++) {
        int linha_atual = n.tam_retangulo.y_inicial + 1 + i;
        if (linha_atual > alt_tela) break; 
        t_lincol(linha_atual, n.tam_retangulo.x_inicial); 
        printf("%.*s", tam_x_visivel, n.texto + char_idx);
        char_idx += n.tam_retangulo.tam_x; 
    }
}
void grava_arquivo(GerenciadorApp *app, const char *nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "w");
    if (arq == NULL) return;

    for (int i = 0; i < app->quantidade; i++) {
        Nota n = app->vetor_notas[i];
        fprintf(arq, "%s %d %d %d %d %d %d %d \"%s\"\n",
                n.etiqueta, n.cor_retangulo.red, n.cor_retangulo.green, n.cor_retangulo.blue,
                n.tam_retangulo.x_inicial, n.tam_retangulo.y_inicial, n.tam_retangulo.tam_x, n.tam_retangulo.tam_y,
                n.texto);
    }
    fclose(arq);
}
int nota_passa_filtro(GerenciadorApp *app, Nota n) {
    if (strlen(app->texto_busca) > 0 && strstr(n.texto, app->texto_busca) == NULL) {
        return 0; 
    }
    if (strlen(app->etiqueta_busca) > 0 && strncmp(n.etiqueta, app->etiqueta_busca, strlen(app->etiqueta_busca)) != 0) {
        return 0;
    }
    return 1;
}
int obtem_indice_nota_corrente(GerenciadorApp *app) {
    for (int i = app->quantidade - 1; i >= 0; i--) {
        Nota n = app->vetor_notas[i];
        if (app->cursor_x >= n.tam_retangulo.x_inicial && app->cursor_x < n.tam_retangulo.x_inicial + n.tam_retangulo.tam_x &&
            app->cursor_y >= n.tam_retangulo.y_inicial && app->cursor_y < n.tam_retangulo.y_inicial + n.tam_retangulo.tam_y) {
            return i;
        }
        if (nota_passa_filtro(app, n)) { 
            if (app->cursor_x >= n.tam_retangulo.x_inicial && app->cursor_x < n.tam_retangulo.x_inicial + n.tam_retangulo.tam_x &&
                app->cursor_y >= n.tam_retangulo.y_inicial && app->cursor_y < n.tam_retangulo.y_inicial + n.tam_retangulo.tam_y) {
                return i;
            }
        }
    }
    
    return -1; 
}

void executa_modo_principal(GerenciadorApp *app) {
    t_limpa();
    for(int i = 0; i < app->quantidade; i++) {
        if (nota_passa_filtro(app, app->vetor_notas[i])) {
            desenha_nota(app->vetor_notas[i]);
        }
    }
    app->indice_nota_corrente = obtem_indice_nota_corrente(app);
    if (app->indice_nota_corrente != -1) {
        t_cursor(c_bloco, c_pisca);
    } else {
        t_cursor(c_barra, c_pisca);
    }
    t_cornormal();
    t_lincol(app->cursor_y, app->cursor_x);
    tecla_t tec = t_tecla();

    switch ((int)tec) {
        case T_ESC: 
        case T_CTRL_C:
            app->modo_atual = MODO_TERMINAR; 
            break;
        case 'b': 
            app->modo_atual = MODO_EDICAO_TEXTO_BUSCA;
            break;
            
        case 'B': 
            app->modo_atual = MODO_EDICAO_ETIQUETA_BUSCA;
            break;
        case 'i':
            if (app->indice_nota_corrente > 0) {
                Nota nota_movida = app->vetor_notas[app->indice_nota_corrente];
                for (int j = app->indice_nota_corrente; j > 0; j--) {
                    app->vetor_notas[j] = app->vetor_notas[j - 1];
                }
                app->vetor_notas[0] = nota_movida;
            }
            break;

        case 'f':
            if (app->indice_nota_corrente != -1 && app->indice_nota_corrente < app->quantidade - 1) {
                Nota nota_movida = app->vetor_notas[app->indice_nota_corrente];
                for (int j = app->indice_nota_corrente; j < app->quantidade - 1; j++) {
                    app->vetor_notas[j] = app->vetor_notas[j + 1];
                }
                app->vetor_notas[app->quantidade - 1] = nota_movida;
            }
            break;
        case T_DIREITA: 
        case 'l':
            app->cursor_x++; break;
            
        case T_ESQUERDA:
        case 'h':
            if (app->cursor_x > 1) app->cursor_x--; break;
            
        case T_BAIXO:
        case 'j':
            app->cursor_y++; break;
            
        case T_CIMA:
        case 'k':
            if (app->cursor_y > 1) app->cursor_y--; break;
        case T_S_DIREITA:
        case 'L':
            if (app->indice_nota_corrente != -1) app->vetor_notas[app->indice_nota_corrente].tam_retangulo.x_inicial++;
            app->cursor_x++; break;
            
        case T_S_ESQUERDA:
        case 'H':
            if (app->indice_nota_corrente != -1) {
                if (app->vetor_notas[app->indice_nota_corrente].tam_retangulo.x_inicial > 1) { 
                    app->vetor_notas[app->indice_nota_corrente].tam_retangulo.x_inicial--;
                    app->cursor_x--; 
                }
            } else if (app->cursor_x > 1) {
                app->cursor_x--;
            }
            break;
            
        case T_S_BAIXO:
        case 'J':
            if (app->indice_nota_corrente != -1) app->vetor_notas[app->indice_nota_corrente].tam_retangulo.y_inicial++;
            app->cursor_y++; break;
            
        case T_S_CIMA:
        case 'K':
            if (app->indice_nota_corrente != -1) {
                if (app->vetor_notas[app->indice_nota_corrente].tam_retangulo.y_inicial > 1) { 
                    app->vetor_notas[app->indice_nota_corrente].tam_retangulo.y_inicial--;
                    app->cursor_y--; 
                }
            } else if (app->cursor_y > 1) {
                app->cursor_y--;
            }
            break;
        case T_C_DIREITA:
        case T_CTRL_L:
            if (app->indice_nota_corrente != -1) app->vetor_notas[app->indice_nota_corrente].tam_retangulo.tam_x++;
            break;
            
        case T_C_BAIXO:
        case T_CTRL_J:
            if (app->indice_nota_corrente != -1) app->vetor_notas[app->indice_nota_corrente].tam_retangulo.tam_y++;
            break;
            
        case T_C_ESQUERDA:
        case T_CTRL_H:
            if (app->indice_nota_corrente != -1) {
                if (app->vetor_notas[app->indice_nota_corrente].tam_retangulo.x_inicial > 1) {
                    app->vetor_notas[app->indice_nota_corrente].tam_retangulo.x_inicial--;
                    app->vetor_notas[app->indice_nota_corrente].tam_retangulo.tam_x++;
                }
            }
            break;
            
        case T_C_CIMA: 
        case T_CTRL_K:
            if (app->indice_nota_corrente != -1) {
                if (app->vetor_notas[app->indice_nota_corrente].tam_retangulo.y_inicial > 1) {
                    app->vetor_notas[app->indice_nota_corrente].tam_retangulo.y_inicial--;
                    app->vetor_notas[app->indice_nota_corrente].tam_retangulo.tam_y++;
                }
            }
            break;
        case T_SA_DIREITA:
        case T_A_DIREITA: 
        case T_CTRL_O:
            if (app->indice_nota_corrente != -1 && app->vetor_notas[app->indice_nota_corrente].tam_retangulo.tam_x > 5) {
                app->vetor_notas[app->indice_nota_corrente].tam_retangulo.x_inicial++;
                app->vetor_notas[app->indice_nota_corrente].tam_retangulo.tam_x--;
                if (app->cursor_x < app->vetor_notas[app->indice_nota_corrente].tam_retangulo.x_inicial) app->cursor_x++;
            }
            break;
            
        case T_SA_ESQUERDA:
        case T_A_ESQUERDA: 
        case T_CTRL_Y:
            if (app->indice_nota_corrente != -1 && app->vetor_notas[app->indice_nota_corrente].tam_retangulo.tam_x > 5) {
                app->vetor_notas[app->indice_nota_corrente].tam_retangulo.tam_x--;
                if (app->cursor_x >= app->vetor_notas[app->indice_nota_corrente].tam_retangulo.x_inicial + app->vetor_notas[app->indice_nota_corrente].tam_retangulo.tam_x) app->cursor_x--;
            }
            break;
            
        case T_SA_BAIXO:
        case T_A_BAIXO: 
        case T_CTRL_U:
            if (app->indice_nota_corrente != -1 && app->vetor_notas[app->indice_nota_corrente].tam_retangulo.tam_y > 3) {
                app->vetor_notas[app->indice_nota_corrente].tam_retangulo.y_inicial++;
                app->vetor_notas[app->indice_nota_corrente].tam_retangulo.tam_y--;
                if (app->cursor_y < app->vetor_notas[app->indice_nota_corrente].tam_retangulo.y_inicial) app->cursor_y++;
            }
            break;
            
        case T_SA_CIMA:
        case T_A_CIMA: 
        case T_CTRL_I:
            if (app->indice_nota_corrente != -1 && app->vetor_notas[app->indice_nota_corrente].tam_retangulo.tam_y > 3) {
                app->vetor_notas[app->indice_nota_corrente].tam_retangulo.tam_y--;
                if (app->cursor_y >= app->vetor_notas[app->indice_nota_corrente].tam_retangulo.y_inicial + app->vetor_notas[app->indice_nota_corrente].tam_retangulo.tam_y) app->cursor_y--;
            }
            break;
        case 'p': {
            if (app->quantidade > 0) {
                Nota nota_topo = app->vetor_notas[app->quantidade - 1];
                app->cursor_x = nota_topo.tam_retangulo.x_inicial + (nota_topo.tam_retangulo.tam_x / 2);
                app->cursor_y = nota_topo.tam_retangulo.y_inicial + (nota_topo.tam_retangulo.tam_y / 2);
            }
            break;
        }
        case 'n':
            if (app->quantidade >= app->capacidade) {
                int nova_cap = app->capacidade + 5;
                Nota *temp = realloc(app->vetor_notas, nova_cap * sizeof(Nota));
                if (temp == NULL) break; 
                app->vetor_notas = temp;
                app->capacidade = nova_cap;
            }
            Nota nova_nota;
            strcpy(nova_nota.etiqueta, "NEW");
            nova_nota.cor_retangulo.red = 220;
            nova_nota.cor_retangulo.green = 220;
            nova_nota.cor_retangulo.blue = 50;
            nova_nota.tam_retangulo.x_inicial = app->cursor_x - 3;
            nova_nota.tam_retangulo.y_inicial = app->cursor_y - 1;
            nova_nota.tam_retangulo.tam_x = 14;
            nova_nota.tam_retangulo.tam_y = 4;
            strcpy(nova_nota.texto, "Texto padrao");
            
            app->vetor_notas[app->quantidade] = nova_nota;
            app->quantidade++;
            break;
        case T_DEL:
        case 'd':
            if (app->indice_nota_corrente != -1) {
                app->ultima_removida = app->vetor_notas[app->indice_nota_corrente];
                app->tem_removida = 1;
                for (int i = app->indice_nota_corrente; i < app->quantidade - 1; i++) {
                    app->vetor_notas[i] = app->vetor_notas[i + 1];
                }
                app->quantidade--;
            }
            break;
        case T_INS:
        case 'I':
            if (app->tem_removida) {
                if (app->quantidade >= app->capacidade) {
                    int nova_cap = app->capacidade + 5;
                    Nota *temp = realloc(app->vetor_notas, nova_cap * sizeof(Nota));
                    if (temp == NULL) break;
                    app->vetor_notas = temp;
                    app->capacidade = nova_cap;
                }
                app->ultima_removida.tam_retangulo.x_inicial = app->cursor_x - 3;
                app->ultima_removida.tam_retangulo.y_inicial = app->cursor_y - 1;
                
                app->vetor_notas[app->quantidade] = app->ultima_removida;
                app->quantidade++;
                app->tem_removida = 0; 
            }
            break;
        case 'g':
            grava_arquivo(app, "notas.txt");
            break;

        case 'e': {
            if (app->indice_nota_corrente != -1) {
                app->modo_atual = MODO_EDICAO_TEXTO;
                strcpy(app->texto_edicao, app->vetor_notas[app->indice_nota_corrente].texto);
                app->cursor_texto = strlen(app->texto_edicao); 
            }
            break;
        }
        case 'c': {
            if (app->indice_nota_corrente != -1) {
                app->modo_atual = MODO_EDICAO_COR;
                app->cor_edicao = app->vetor_notas[app->indice_nota_corrente].cor_retangulo;
                app->comp_cor_selecionado = 0; 
            }
            break;
        }
        case 't': {
            if (app->indice_nota_corrente != -1) {
                app->modo_atual = MODO_EDICAO_ETIQUETA;
                strcpy(app->etiqueta_edicao, app->vetor_notas[app->indice_nota_corrente].etiqueta);
                app->cursor_etiqueta = strlen(app->etiqueta_edicao);
            }
            break;
        }
        default:
            break;
    }
}
void executa_modo_edicao_texto(GerenciadorApp *app) {
    t_limpa();
    t_lincol(2, 2);
    t_cortexto(200, 200, 200);
    printf("MODO DE EDICAO DE TEXTO (Enter para guardar, Esc para cancelar)");

    t_lincol(5, 5);
    t_cortexto(255, 255, 255);
    printf("%s", app->texto_edicao);
    t_cornormal();
    t_cursor(c_sublinha, c_pisca);
    t_lincol(5, 5 + app->cursor_texto);
    tecla_t tec = t_tecla();
    int len = strlen(app->texto_edicao);
    switch ((int)tec) {
        case T_ESC:
            app->modo_atual = MODO_PRINCIPAL;
            break;   
        case T_ENTER:
            strcpy(app->vetor_notas[app->indice_nota_corrente].texto, app->texto_edicao);
            app->modo_atual = MODO_PRINCIPAL;
            break;
        case T_ESQUERDA:
            if (app->cursor_texto > 0) app->cursor_texto--;
            break;
        case T_DIREITA:
            if (app->cursor_texto < len) app->cursor_texto++;
            break;
        case T_BACKSPACE: 
            if (app->cursor_texto > 0) {
                for (int i = app->cursor_texto - 1; i < len; i++) {
                    app->texto_edicao[i] = app->texto_edicao[i + 1];
                }
                app->cursor_texto--;
            }
            break;

        case T_DEL:
            if (app->cursor_texto < len) {
                for (int i = app->cursor_texto; i < len; i++) {
                    app->texto_edicao[i] = app->texto_edicao[i + 1];
                }
            }
            break;

        default:
            if (tec >= 32 && tec <= 126 && tec != '"' && len < 100) {
                for (int i = len; i >= app->cursor_texto; i--) {
                    app->texto_edicao[i + 1] = app->texto_edicao[i];
                }
                app->texto_edicao[app->cursor_texto] = (char)tec;
                app->cursor_texto++;
            }
            break;
    }
}
void executa_modo_edicao_cor(GerenciadorApp *app) { 
    t_limpa();
    t_lincol(2, 2);
    t_cortexto(200, 200, 200);
    printf("MODO DE EDICAO DE COR (Enter para salvar, Esc para cancelar)");
    t_corfundo(app->cor_edicao.red, app->cor_edicao.green, app->cor_edicao.blue);
    for(int i = 0; i < 5; i++) {
        t_lincol(5 + i, 5);
        printf("%*s", 30, "");
    }
    t_cornormal();
    t_lincol(12, 5);
    if (app->comp_cor_selecionado == 0) t_cortexto(255, 50, 50); else t_cortexto(150, 150, 150);
    printf("[R]ed: %3d   ", app->cor_edicao.red);

    if (app->comp_cor_selecionado == 1) t_cortexto(50, 255, 50); else t_cortexto(150, 150, 150);
    printf("[G]reen: %3d   ", app->cor_edicao.green);

    if (app->comp_cor_selecionado == 2) t_cortexto(100, 150, 255); else t_cortexto(150, 150, 150);
    printf("[B]lue: %3d", app->cor_edicao.blue);

    t_cornormal();

    tecla_t tec = t_tecla();
    int *comp_atual = NULL;
    if (app->comp_cor_selecionado == 0) comp_atual = &app->cor_edicao.red;
    else if (app->comp_cor_selecionado == 1) comp_atual = &app->cor_edicao.green;
    else comp_atual = &app->cor_edicao.blue;

    switch ((int)tec) {
        case T_ESC: 
            app->modo_atual = MODO_PRINCIPAL; 
            break;
            
        case T_ENTER:
            app->vetor_notas[app->indice_nota_corrente].cor_retangulo = app->cor_edicao;
            app->modo_atual = MODO_PRINCIPAL;
            break;
        case 'r': case 'e': app->comp_cor_selecionado = 0; break;
        case 'g': case 'v': app->comp_cor_selecionado = 1; break;
        case 'b': case 'a': app->comp_cor_selecionado = 2; break;
        case T_DIREITA: 
            app->comp_cor_selecionado = (app->comp_cor_selecionado + 1) % 3; 
            break;
        case T_ESQUERDA: 
            app->comp_cor_selecionado = (app->comp_cor_selecionado + 2) % 3; 
            break;
        case T_CIMA: 
            if (*comp_atual < 255) (*comp_atual)++; 
            break;
        case T_BAIXO: 
            if (*comp_atual > 0) (*comp_atual)--; 
            break;
        case T_S_CIMA: 
            *comp_atual += 15; 
            if (*comp_atual > 255) *comp_atual = 255; 
            break;
        case T_S_BAIXO: 
            *comp_atual -= 15; 
            if (*comp_atual < 0) *comp_atual = 0; 
            break;
            
        default:
            break;
    }
}
void executa_modo_edicao_etiqueta(GerenciadorApp *app) {
    t_limpa();
    t_lincol(2, 2);
    t_cortexto(200, 200, 200);
    printf("MODO DE EDICAO DE ETIQUETA (Enter p/ guardar, Shift+Enter p/ todas, Esc p/ cancelar)");
    t_lincol(5, 5);
    t_cortexto(255, 255, 255);
    printf("Etiqueta (Max 3 carateres): %s", app->etiqueta_edicao);
    t_cornormal();
    t_cursor(c_sublinha, c_pisca);
    t_lincol(5, 33 + app->cursor_etiqueta);
    tecla_t tec = t_tecla();
    int len = strlen(app->etiqueta_edicao);
    switch ((int)tec) {
        case T_ESC:
            app->modo_atual = MODO_PRINCIPAL;
            break;
            
        case T_ENTER:

            if (len == 3) {
                strcpy(app->vetor_notas[app->indice_nota_corrente].etiqueta, app->etiqueta_edicao);
                app->modo_atual = MODO_PRINCIPAL;
            }
            break;
            
        
        case '\n': case '\r': 
            break; 
            
        case T_BACKSPACE:
            if (len > 0) {
                app->etiqueta_edicao[len - 1] = '\0';
                app->cursor_etiqueta--;
            }
            break;
            
        default:
            if (len < 3) {
                if (tec >= 'a' && tec <= 'z') tec -= 32;
                if ((tec >= 'A' && tec <= 'Z') || (tec >= '0' && tec <= '9')) {
                    app->etiqueta_edicao[len] = (char)tec;
                    app->etiqueta_edicao[len + 1] = '\0';
                    app->cursor_etiqueta++;
                }
            }
            break;
    }
}
void executa_modo_busca_etiqueta(GerenciadorApp *app) {
    t_limpa();
    t_lincol(2, 2); t_cortexto(200, 200, 200);
    printf("MODO DE BUSCA POR ETIQUETA (Enter p/ aplicar, Esc p/ limpar)");
    t_lincol(5, 5); t_cortexto(255, 255, 255);
    printf("Etiqueta Busca: %s", app->etiqueta_busca);
    t_cornormal(); t_cursor(c_sublinha, c_pisca);
    int len = strlen(app->etiqueta_busca);
    t_lincol(5, 21 + len);
    tecla_t tec = t_tecla();
    
    switch ((int)tec) {
        case T_ESC:
        case T_CTRL_C:
            app->etiqueta_busca[0] = '\0'; 
            app->modo_atual = MODO_PRINCIPAL; 
            break;
        case T_ENTER:
            app->modo_atual = MODO_PRINCIPAL;
            break;
        case T_BACKSPACE:
            if (len > 0) app->etiqueta_busca[len - 1] = '\0';
            break;
        default:
            if (len < 3) {
                if (tec >= 'a' && tec <= 'z') tec -= 32; 
                if ((tec >= 'A' && tec <= 'Z') || (tec >= '0' && tec <= '9')) {
                    app->etiqueta_busca[len] = (char)tec;
                    app->etiqueta_busca[len + 1] = '\0';
                }
            }
            break;
    }
}
void executa_modo_busca_texto(GerenciadorApp *app) {
    t_limpa();
    t_lincol(2, 2); t_cortexto(200, 200, 200);
    printf("MODO DE BUSCA POR TEXTO (Enter para aplicar, Esc para limpar filtro)");
    
    t_lincol(5, 5); t_cortexto(255, 255, 255);
    printf("Buscar: %s", app->texto_busca);
    
    t_cornormal(); t_cursor(c_sublinha, c_pisca);
    t_lincol(5, 13 + app->cursor_texto_busca); 
    tecla_t tec = t_tecla();
    int len = strlen(app->texto_busca);

    switch ((int)tec) {
        case T_ESC: 
        case T_CTRL_C:
            app->texto_busca[0] = '\0';
            app->cursor_texto_busca = 0;
            app->modo_atual = MODO_PRINCIPAL; 
            break;
        case T_ENTER: 
            app->modo_atual = MODO_PRINCIPAL; 
            break;
        case T_ESQUERDA: 
            if (app->cursor_texto_busca > 0) app->cursor_texto_busca--; 
            break;
        case T_DIREITA: 
            if (app->cursor_texto_busca < len) app->cursor_texto_busca++; 
            break;
        case T_BACKSPACE:
            if (app->cursor_texto_busca > 0) {
                for (int i = app->cursor_texto_busca - 1; i < len; i++) {
                    app->texto_busca[i] = app->texto_busca[i + 1];
                }
                app->cursor_texto_busca--;
            }
            break;
        default:
            if (tec >= 32 && tec <= 126 && len < 100) {
                for (int i = len; i >= app->cursor_texto_busca; i--) {
                    app->texto_busca[i + 1] = app->texto_busca[i];
                }
                app->texto_busca[app->cursor_texto_busca] = (char)tec;
                app->cursor_texto_busca++;
            }
            break;
    }
}
int main() {
    GerenciadorApp app;
    inicializa_e_le_arquivo(&app, "notas.txt");
    t_inicia();
    while (app.modo_atual != MODO_TERMINAR) {
        switch (app.modo_atual) {
            case MODO_PRINCIPAL:
                executa_modo_principal(&app);
                break;
            case MODO_EDICAO_TEXTO:
                executa_modo_edicao_texto(&app);
                break;
            case MODO_EDICAO_COR:
                executa_modo_edicao_cor(&app);
                break;
            case MODO_EDICAO_ETIQUETA:
                executa_modo_edicao_etiqueta(&app);
                break;
            case MODO_EDICAO_TEXTO_BUSCA:
                executa_modo_busca_texto(&app);
                break;
            case MODO_EDICAO_ETIQUETA_BUSCA:
                executa_modo_busca_etiqueta(&app);
                break;
            default:
                break;
        }
    }
    t_fim();
    free(app.vetor_notas);
    return 0;
}