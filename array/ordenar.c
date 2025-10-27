#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirArreglo(int n, int arreglo[]) {
    printf("[");
    for(int i = 0; i < n; i++){
        if (i != n-1) {
            printf("%d,", arreglo[i]);
        }else{
            printf("%d]\n", arreglo[i]);
        }
    }
}

void generarAleatorio(int n, int arreglo[]) {
    int numero;
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        numero = rand() % 10; // 0..9
        arreglo[i] = numero;
    }
}

void ordenarArreglo(int n, int arreglo[]) {
    int temp;
    int indiceMenor;

    for(int i = 0; i < n - 1; i++){
        indiceMenor = i;
        for(int j = i + 1; j < n; j++) {
            if(arreglo[j] < arreglo[indiceMenor]){
                indiceMenor = j; //encontre el menor valor
            }
        }
        if(indiceMenor != i){
            temp = arreglo[i];
            arreglo[i] = arreglo[indiceMenor];
            arreglo[indiceMenor] = temp;
        }
    }
}

int sumarArreglo(int n, int arreglo[]) {
    int suma = 0;
    for(int i = 0; i < n; i++){
        suma = suma + arreglo[i];
    }
    return suma;
}

int main(){
    int n = 20;
    int arreglo[n];

    //inicializo el arreglo
    for(int i=0; i < n; i++){
        arreglo[i] = 0;
    }

    //genero un arreglo aleatorio
    generarAleatorio(n, arreglo);

    //imprimo el arreglo
    imprimirArreglo(n, arreglo);

    //ordeno el arreglo Selection Sort
    ordenarArreglo(n, arreglo);

    //Imprimo arreglo ordenado
    imprimirArreglo(n, arreglo);
    int total = sumarArreglo(n, arreglo);
    printf("La suma de los elementos es %d\n", total);
    return 0;
}