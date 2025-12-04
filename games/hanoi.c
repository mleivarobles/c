/*
Torres de Hanoi
Mover N discos de A → C usando B
  1. Mover N−1 discos de A → B usando C
  2. Mover 1 disco de A → C
  3. Mover N−1 discos de B → C usando A

gcc hanoi.c -o hanoi
  */

#include <stdio.h>

void hanoi(int n, char origen, char auxiliar, char destino){
    if (n == 1) {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }
        // Mover n-1 discos a la torre auxiliar
    hanoi(n - 1, origen, destino, auxiliar);

    // Mover el disco mayor
    printf("Mover disco %d de %c a %c\n", n, origen, destino);

    // Mover los n-1 discos desde auxiliar a destino
    hanoi(n - 1, auxiliar, origen, destino);
}

int main(void){
    int n = 0;

    printf("Ingresa cantidad de discos: ");
    scanf("%d", &n);


    hanoi(n, 'A', 'B', 'C');

    return 0;
}