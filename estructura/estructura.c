#include <stdio.h>
#include <string.h>

typedef struct persona{
    char nombre[50];
    int edad;
} Persona;

int main(){

    Persona lista[10];

    Persona p1 = {"Mario",49};
    printf("Mi nombre es %s y tengo %d años", p1.nombre, p1.edad);

    strcpy(lista[0].nombre, "Juan");
    lista[0].edad = 23;

    strcpy(lista[1].nombre, "Pedro");
    lista[1].edad = 66;

    strcpy(lista[2].nombre, "Maria");
    lista[2].edad = 50;

    for(int i = 0; i < 3; i++){
        printf("\n[%d] = %s tiene %d años", i, lista[i].nombre, lista[i].edad);
    }
    return 0;
}