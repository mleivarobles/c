/*
1.- Escribe un programa en C que lea las 5 calificaciones de 10 estudiantes. 
Las almacene en un estructura y calcule el promedio de cada alumno.

2- Posteriormente debes crear un archivo con la lista de estudiantes con sus respectivas
notas y promedios. Se muestra ejemplo del archivo de salida:
Alumno  Nota1   Nota2   Nota3   Nota4   Nota5   Promedio
*/

#include <stdio.h>

typedef struct alumno{
    char nombre[50]; //alumno
    float notas[5]; //notas
} Alumno;

int main(){

    Alumno alumnos[10];

    //Persona p1 = {"Mario",49};
    int n;

    printf("Ingresa la cantidad alumnos: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Ingresa Nombre alumno %i: ", i);
        scanf("%s", alumnos[i].nombre);
    }

    for(int i = 0; i < n; i++){
        printf("Nombre alumno %i: %s\n", i, alumnos[i].nombre);
    }
}