#include <stdio.h>

//Ejercicio 3 P3 Guillermo Vaca (Archivos 2)

struct Chochos{
  char  color[10];
  char  sabor[10];
  char precio[4];
};

int main() {
    FILE *file;
    struct Chochos cc[2];
    int i;
    const char *filename = "archivo.txt";
    //const char *additional_message = "Añadiendo más información al archivo.\n";
    char buffer[256];

    // Abrir el archivo para añadir información
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error al abrir el archivo para añadir información.\n");
        return 1;
    }

    // Añadir la info de la estructura al archivo
    fputs("Color   Sabor   Precio\n", file);
    fputs("----------------------\n", file);
    for(i=0; i<2; i++){
        printf("Ingrese el color  : ");scanf("%s",cc[i].color);
        printf("Ingrese el sabor  : ");scanf("%s",cc[i].sabor);
        printf("Ingrese el precio : ");scanf("%s",cc[i].precio);
        fputs(cc[i].color, file);
        fputs("  ", file);
        fputs(cc[i].sabor, file);
        fputs("  ", file);
        fputs(cc[i].precio, file);
        fputs("\n", file);
    }


    // Cerrar el archivo
    fclose(file);

    // Abrir el archivo para lectura
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return 1;
    }

    // Leer y mostrar el contenido del archivo
    printf("Contenido del archivo '%s':\n", filename);
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Cerrar el archivo
    fclose(file);

    return 0;
}