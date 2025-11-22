#include <stdio.h>

/*
  xadrez.c
  Implementa os desafios: Movimentação de peças de xadrez
  - Nível Novato: Torre (for), Bispo (while), Rainha (do-while)
  - Nível Aventureiro: Cavalo com loops aninhados (for + while)
  - Nível Mestre: versões recursivas e Cavalo com loops complexos
  Requisitos base: imprimir direções a cada casa, separar peças com linhas em branco.
*/

/* ---------- NÍVEL NOVATO ---------- */

/* Torre: mover N casas para a direita (usa for) */
void torre_mov_for(int casas) {
    printf("=== Torre (for) ===\n");
    for (int i = 0; i < casas; i++) {
        printf("Direita\n");
    }
    printf("\n");
}

/* Bispo: mover N casas na diagonal cima-direita (usa while) */
void bispo_mov_while(int casas) {
    printf("=== Bispo (while) ===\n");
    int cont = 0;
    while (cont < casas) {
        printf("Cima, Direita\n");
        cont++;
    }
    printf("\n");
}

/* Rainha: mover N casas para a esquerda (usa do-while) */
void rainha_mov_do_while(int casas) {
    printf("=== Rainha (do-while) ===\n");
    int cont = 0;
    if (casas <= 0) {
        printf("\n");
        return;
    }
    do {
        printf("Esquerda\n");
        cont++;
    } while (cont < casas);
    printf("\n");
}

/* ---------- NÍVEL AVENTUREIRO (Cavalo) ---------- */

/* Cavalo: mover em L (duas casas para baixo e uma para a esquerda)
   Deve usar loops aninhados: um for e um while (ou do-while). */
void cavalo_mov_nested(int down, int left) {
    printf("=== Cavalo (loops aninhados) ===\n");
    /* Exemplo pedido: duas para baixo e uma para a esquerda */
    /* Vamos usar um for externo (para cada 'L' completo) e um while interno para os 'down' */
    int movimentosL = 1; /* número de movimentos em L a executar (aqui apenas 1 L) */
    for (int m = 0; m < movimentosL; m++) {
        int i = 0;
        while (i < down) {
            printf("Baixo\n");
            i++;
        }
        /* após descer 'down' casas, mover 'left' casas */
        for (int j = 0; j < left; j++) {
            printf("Esquerda\n");
        }
    }
    printf("\n");
}

/* ---------- NÍVEL MESTRE (recursividade e loops complexos) ---------- */

/* Funções recursivas que imprimem a direção a cada casa (caso-base: quando n==0 para parar) */
void torre_mov_rec(int casas_remaining) {
    if (casas_remaining <= 0) return;
    printf("Direita\n");
    torre_mov_rec(casas_remaining - 1);
}

void bispo_mov_rec(int casas_remaining) {
    if (casas_remaining <= 0) return;
    printf("Cima, Direita\n");
    bispo_mov_rec(casas_remaining - 1);
}

void rainha_mov_rec(int casas_remaining) {
    if (casas_remaining <= 0) return;
    printf("Esquerda\n");
    rainha_mov_rec(casas_remaining - 1);
}

/* Cavalo nível mestre: duas casas para cima e uma para a direita (movimento em L) usando loops complexos.
   Aqui ilustramos uso de loops aninhados com múltiplas variáveis e uso de continue/break. */
void cavalo_mov_complex(int up, int right) {
    printf("=== Cavalo (complexo) ===\n");
    /* vamos simular um conjunto de tentativas até completar o L:
       - loop externo controla "tentativas" (simula condições múltiplas)
       - loop interno faz as etapas verticais e horizontais com continue/break
    */
    int attempts = 0;
    int max_attempts = 5; /* só para exemplo; garantimos terminar internamente */
    while (attempts < max_attempts) {
        int moved_up = 0;
        for (int step = 0; step < up + 2; step++) { /* passo com margem */
            if (moved_up < up) {
                printf("Cima\n");
                moved_up++;
                if (moved_up < up) continue; /* continue para seguir subindo */
            }
            /* quando já subiu 'up' casas, mover para a direita */
            int moved_right = 0;
            while (moved_right < right) {
                printf("Direita\n");
                moved_right++;
                /* exemplo de controle: se algo hipotético acontecesse, poderíamos break; */
            }
            /* já completou o L */
            attempts = max_attempts; /* força saída do while externo */
            break;
        }
        attempts++;
    }
    printf("\n");
}

/* ---------- main: chama tudo em sequência ---------- */

int main(void) {
    /* Valores fixos conforme enunciado (podem ser alterados diretamente no código) */
    const int torre_casas = 5;   /* Torre: 5 casas para a direita (novato). */ 
    const int bispo_casas = 5;   /* Bispo: 5 casas na diagonal cima-direita (novato). */
    const int rainha_casas = 8;  /* Rainha: 8 casas para a esquerda (novato). */
    const int cavalo_down = 2;   /* Cavalo (aventureiro): 2 para baixo */
    const int cavalo_left = 1;   /* Cavalo (aventureiro): 1 para a esquerda */
    const int mestre_up = 2;     /* Cavalo mestre: 2 para cima */
    const int mestre_right = 1;  /* Cavalo mestre: 1 para a direita */

    /* NÍVEL NOVATO */
    torre_mov_for(torre_casas);       /* usa for */
    bispo_mov_while(bispo_casas);     /* usa while */
    rainha_mov_do_while(rainha_casas);/* usa do-while */

    /* NÍVEL AVENTUREIRO */
    cavalo_mov_nested(cavalo_down, cavalo_left); /* loops aninhados (for + while) */

    /* NÍVEL MESTRE - recursivo e complexo */
    printf("=== NÍVEL MESTRE (recursivo) ===\n");
    printf("--- Torre (recursiva) ---\n");
    torre_mov_rec(torre_casas);
    printf("\n--- Bispo (recursivo) ---\n");
    bispo_mov_rec(bispo_casas);
    printf("\n--- Rainha (recursiva) ---\n");
    rainha_mov_rec(rainha_casas);
    printf("\n");

    /* Cavalo nível mestre (loops complexos) */
    cavalo_mov_complex(mestre_up, mestre_right);

    return 0;
}
