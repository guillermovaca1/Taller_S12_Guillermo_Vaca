#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Ejercicio 5 P3 Guillermo Vaca (Archivos y Estructuras)

// Definición de la estructura
struct Persona {
    char nombre[50];
    int edad;
};

// Función para escribir datos en el archivo
void escribirArchivo(struct Persona p) {
    FILE *archivo = fopen("e:\\datos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(archivo, "%s %d\n", p.nombre, p.edad);
    fclose(archivo);
}

// Función para leer y mostrar datos del archivo
void leerArchivo() {
    FILE *archivo = fopen("e:\\datos.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    struct Persona p;
    fscanf(archivo, "%s %d", p.nombre, &p.edad);
    printf("Nombre: %s\nEdad: %d\n", p.nombre, p.edad);
    fclose(archivo);
}

// Función para modificar datos en el archivo
void modificarArchivo(struct Persona p) {
    FILE *archivo = fopen("e:\\datos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(archivo, "%s %d\n", p.nombre, p.edad);
    fclose(archivo);
}

int main() {
    struct Persona p1;
    //strcpy(p1.nombre, "Juan");
    //p1.edad = 30;
    // Lectura de datos para la estructura
    printf("Ingrese nombre : "); scanf("%s",p1.nombre);
    printf("Ingrese edad   : "); scanf("%d",&p1.edad);
    printf("\n");

    // Escribir datos en el archivo
    escribirArchivo(p1);

    // Leer y mostrar datos del archivo
    printf("Contenido del archivo:\n");
    leerArchivo();

    // Modificar datos en la estructura
    //strcpy(p1.nombre, "Maria");
    //p1.edad = 25;
    printf("\n");
    printf("Ingrese nombre : "); scanf("%s",p1.nombre);
    printf("Ingrese edad   : "); scanf("%d",&p1.edad);
    printf("\n");


    // Modificar datos en el archivo
    modificarArchivo(p1);

    // Leer y mostrar datos del archivo nuevamente
    printf("\nContenido del archivo después de modificar:\n");
    leerArchivo();

    return 0;
}