/*
Conjetura de Collatz
Sea la siguiente operación, aplicable a cualquier número entero positivo:
Si el número es par, se divide entre 2.
Si el número es impar, se multiplica por 3 y se suma 1.

gcc -o collatz collatz.c

*/

#include <stdio.h>

void collatz(long long int n){
    int numeros[2] = {0};

    while (n != 1){
        printf("%lld ", n);

        if( n % 2 == 0){
            n = n / 2;
            numeros[0]++;
        } else {
            n = 3 * n + 1;
            numeros[1]++;
        }
    }
    printf("1\n");
    printf("pares: %d\n", numeros[0]);
    printf("impares: %d\n", numeros[1]+1);
}

int main(void){

    long long int n;
    
    printf("Ingresa un numero entero positivo n>0: ");
    scanf(" %lld", &n);

    if (n <= 0 ){
        printf("Entrada invalida. Debes introducir un entero positivo.\n");
        return 1;
    }
    collatz(n);
    return 0;
}