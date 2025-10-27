#include <stdio.h>

int main(){
    int suma = 0;
    for (int i = 0; i <= 500; i++){
        suma = suma + i;
        printf("suma=%d\n", suma);
    }

    printf("La suma de los enteros es : %d\n", suma);
}