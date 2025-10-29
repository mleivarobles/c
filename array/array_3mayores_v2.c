#include <stdio.h>

int main(){

    int arreglo[10] = {74, 2, 5, 65, 22, 56, 73, 33, 6, 55};
    int mayor1, mayor2, mayor3;

    //mayor1 = mayor2 = mayor3 = arreglo[0];

    mayor1 = arreglo[0];
    for(int i = 0; i < 10; i++){
        if (arreglo[i] > mayor1) {
            mayor1 = arreglo[i]; 
        }
    }
    

    printf("Los tres numeros mayores son: %d, %d, %d\n", mayor1, mayor2, mayor3);
    return 0;

}
