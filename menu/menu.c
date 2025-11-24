
//gcc -o menu menu.c
#include <stdio.h>

int main(){

    int opcion;
    do{
        printf("1. Sumar 2 numeros\n");
        printf("2. Restar 2 números\n");
        printf("3. Multiplicar 2 números\n");
        printf("4. Dividir 2 números\n");
        printf("0.- Salir()\n");
        printf("\nSeleecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            float num1, num2, suma;
            printf("Ingresa N°1: ");
            scanf("%f", &num1);
            printf("Ingresa N°2: ");
            scanf("%f", &num2);
            suma = num1 + num2;
            
            printf("La suma de %.2f y %.2f= %.2f\n", num1, num2, suma);            
            break;
        
        default:
            break;
        }


    } while (opcion !=0);

}