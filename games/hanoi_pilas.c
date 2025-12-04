#include <stdio.h>

#define MAX_DISCOS 10

typedef struct {
    int datos[MAX_DISCOS];
    int tope;  // cantidad de elementos en la pila
} Pila;

Pila torres[3];           // 0: A, 1: B, 2: C
char nombres[] = {'A', 'B', 'C'};
int total_discos = 0;

// --------- Operaciones sobre pilas ---------
void init_pila(Pila *p) {
    p->tope = 0;
}

int esta_vacia(Pila *p) {
    return p->tope == 0;
}

void push(Pila *p, int valor) {
    if (p->tope >= MAX_DISCOS) {
        printf("Error: pila llena\n");
        return;
    }
    p->datos[p->tope] = valor;
    p->tope++;
}

int pop(Pila *p) {
    if (esta_vacia(p)) {
        printf("Error: pila vacia\n");
        return -1;  // valor de error
    }
    p->tope--;
    return p->datos[p->tope];
}

// --------- Impresión gráfica ---------
void imprimir_torres() {
    int nivel, t;

    printf("\nEstado de las torres:\n\n");

    // Imprimimos desde el nivel superior al inferior
    for (nivel = total_discos - 1; nivel >= 0; nivel--) {
        for (t = 0; t < 3; t++) {
            if (nivel < torres[t].tope) {
                int disco = torres[t].datos[nivel];
                printf("  %d  ", disco);
            } else {
                printf("  |  ");
            }
        }
        printf("\n");
    }

    printf("----- ----- -----\n");
    printf("  A     B     C\n\n");
}

// --------- Movimiento de discos ---------
void mover_disco(int desde, int hasta) {
    int disco = pop(&torres[desde]);
    push(&torres[hasta], disco);

    printf("Mover disco %d de %c a %c\n",
           disco, nombres[desde], nombres[hasta]);

    imprimir_torres();
}

// --------- Recursión de Hanoi ---------
void hanoi(int n, int origen, int auxiliar, int destino) {
    if (n == 1) {
        mover_disco(origen, destino);
        return;
    }

    hanoi(n - 1, origen, destino, auxiliar);
    mover_disco(origen, destino);
    hanoi(n - 1, auxiliar, origen, destino);
}

// --------- Programa principal ---------
int main() {
    int n, i;

    printf("Ingrese el numero de discos (max %d): ", MAX_DISCOS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISCOS) {
        printf("Numero de discos invalido.\n");
        return 1;
    }

    total_discos = n;

    // Inicializar pilas (torres)
    for (i = 0; i < 3; i++) {
        init_pila(&torres[i]);
    }

    // Colocar todos los discos en la torre A (0)
    // Abajo el mas grande (n), arriba el mas chico (1)
    for (i = n; i >= 1; i--) {
        push(&torres[0], i);
    }

    printf("\nEstado inicial:\n");
    imprimir_torres();

    printf("Secuencia de movimientos:\n");
    hanoi(n, 0, 1, 2);   // 0 = A, 1 = B, 2 = C

    return 0;
}
