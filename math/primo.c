#include <stdio.h>
/*
Evaluar si un numero es primo o no
*/

int main(void){

    int n = 0;
    int count = 0;

    printf("Ingresa un numero entero: ");
    scanf("%d", &n);

    if(n > 2){
        count = 0;
        for (int i = 2; i <= n; i++){
            if((n % i) == 0){
                count++;
            }
            if (count > 1){
                break;
            }
        }
    }
    if (count > 1){
        printf("El numero %d no es primo. Count=%d\n", n, count);
    }else{
        printf("El numero %d es primo. Count=%d\n", n, count);
    }
return 0;
}