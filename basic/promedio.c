#include <stdio.h>

int main(){
    int numero;
    float suma = 0;
    float promedio = 0;

    for (int i = 1; i <=3; i++){
        //
        printf("Ingresa N°%d: ", i);
        scanf("%d", &numero);

        printf("Numero ingresado: %d\n", numero);
         suma = suma + numero;
    }
    promedio = suma / 3;
    printf("El promedio de los numeros es %f\n", promedio);
}