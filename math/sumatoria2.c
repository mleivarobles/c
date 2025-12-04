/*

gcc sumatoria2.c -o sumatoria2 -lm
*/
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main(){

    int k;
    double numerador, denominador;
    double suma = 0.0;
    float termino;

    printf("Ingresa la cantidad de terminos: ");
    scanf("%d", &k);

    for (int i = 0; i <= k; i++){
        numerador = 4 * pow(-1, i);
        denominador = 2 * i + 1;

        termino = (numerador / denominador);
        if( i % 1000 == 0){
            printf("termino %d: %f\n", i, termino);
        }
        suma = suma + termino;
    }
    
    printf("La suma para %d terminos tiende a %.10lf\n", k, suma);
    printf("y M_PI vale: %.10f \n", M_PI);
    return 0;
}