/*
1.- Escribe un programa en C que lea(teclado) las 5 calificaciones de 10 estudiantes. 
Las almacene en un estructura y calcule el promedio de cada alumno.

2- Posteriormente debes crear un archivo con la lista de estudiantes con sus respectivas
notas y promedios. Se muestra ejemplo del archivo de salida:
Alumno  Nota1   Nota2   Nota3   Nota4   Nota5   Promedio

3.- Finalmente debes leer el archivo desde python y mostrar los siguientes resultados por pantalla
    * Promedio General
    * Promedio más alto
    * Promedio más bajo
*/

#include <stdio.h>
#include <string.h>

typedef struct alumno{
    char nombre[50]; //alumno
    float notas[5]; //notas n1= notas[0], n2= notas[1]...., n5= nota[4]
    float promedio; //promedio
} Alumno;

//

int main(){
    Alumno alumnos[10];
    int n;

    printf("Ingresa la cantidad alumnos: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        //ingreso de Alumno
        printf("Ingresa Nombre alumno %d: ", i);
        scanf("%s", alumnos[i].nombre);

        //Ingreso de Notas
        float suma = 0;
        for (int j = 0; j < 5; j++){
            printf("Ingresa Nota %d: ", j);
            scanf("%f", &alumnos[i].notas[j]);
            suma += alumnos[i].notas[j];
        }
        alumnos[i].promedio = suma / 5; //calculo y guardo el promedio del alumno
    }

    //Imprimir listado
    for(int i = 0; i < n; i++){
        printf("Nombre alumno %d: %s\n", i, alumnos[i].nombre);
        for (int j = 0; j < 5; j++){
            printf("Notas %d: %f\n", j, alumnos[i].notas[j]);
        }
        printf("Promedio: %f\n", alumnos[i].promedio);
    }

    //Guarda listado de alumnos en archivo
    FILE *archivo;

    archivo = fopen("listado.txt", "w");
     if (!archivo){
        printf("Error al crear el archivo");
        return 1; //salgo con error
     }
    char linea[200] = "";
    char cadena[10];

    strcat(linea,"Alumno\tNota1\tNota2\tNota3\tNota4\tNota5\tPromedio\n");
    fputs(linea, archivo); //cabecera
    
    linea[0] = '\0';
    
    for (int i = 0; i < n; i++){
        strcat(linea, alumnos[i].nombre);
        strcat(linea, "\t"); //separador tab

        for (int j = 0; j < 5; j++){
            sprintf(cadena, "%.2f", alumnos[i].notas[j]);
            strcat(linea, cadena);
            strcat(linea, "\t");
        }
    sprintf(cadena, "%.2f", alumnos[i].promedio);
    strcat(linea, cadena);
    strcat(linea, "\n");
    fputs(linea, archivo);     
    linea[0] = '\0';
    }
    fclose(archivo);

    printf("Listado OK\n");
    return 0;
}