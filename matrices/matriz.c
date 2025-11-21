#include <stdio.h>

int main(void){
    int n, m;

    printf("Ingresa el numero de filas: ");
    scanf("%d", &n);
    
    printf("Ingresa el numero de columnas: ");
    scanf("%d", &m);

    int matriz[n][m];

    /*Ingreso matriz*/
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("Elemento[%d][%d]= ", i, j);
            scanf("%d", &matriz[i][j]);
        }      
    }

    /*Imprimo matriz*/
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");      
    }

    /*Suma elementos y calculo mayor y menor*/
    int suma = 0, item;
    int menor = matriz[0][0];
    int mayor = menor;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            item = matriz[i][j];
            suma += item;
            if(item < menor){
                menor = item;
            }
            if(item > mayor){
                mayor = item;
            }
        }
    }
    printf("La suma de todos los elementos es= %d\n", suma);  
    printf("El numero menor es= %d\n", menor);
    printf("El numero mayor es= %d\n", mayor);      
}