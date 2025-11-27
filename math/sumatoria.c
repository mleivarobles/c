
// Sumatoria: 1 + 1/2^2 + 1/3^2 + ... + 1/n^2

#include <stdio.h>
int main(){
    int n;
    double suma = 0.0;

    printf("Ingresa el valor de n: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("El valor de n debe ser mayor que 0\n");
        return 1;
    }else{
        for (int i = 1; i < n; i++){
            suma += 1.0 / (i * i);
        }
    }
    printf("El resultado para una precisión de %d es %.10f\n", n , suma);
    return 0;
}