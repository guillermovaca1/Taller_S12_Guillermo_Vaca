#include <stdio.h>
#include <string.h>

//Ejercicio 6 P3 Guillermo Vaca (Datos de CLiente)

struct Cliente {
    char nombre[50];
    char telefono[10];
    char direccion[100];
    char correo[50];
    char cedula[11]; 

};

int validarCedula(const char *cedula) {
    int longitud = strlen(cedula);
    if (longitud != 10) {
        return 0; // Cédula inválida
    }
    int suma = 0;
    int coefi;
    for (int i = 0; i < 9; i++) {
        int digito = cedula[i] - '0'; 
        coefi = (i % 2 == 0) ? 2 : 1;
        int resultado = digito * coefi;
        if (resultado >= 10) {
            resultado -= 9;
        }
        suma += resultado;
    }
    int residuo = suma % 10;
    int digitoVerificador = (residuo == 0) ? 0 : (10 - residuo);
    int ultimoDigito = cedula[9] - '0';
    return digitoVerificador == ultimoDigito;
}
int main() {
    struct Cliente cliente1;
    printf("Ingrese el nombre del cliente: ");
    fgets(cliente1.nombre, 50, stdin);
    printf("Ingrese el teléfono del cliente: ");
    fgets(cliente1.telefono, 15, stdin);
    printf("Ingrese la dirección del cliente: ");
    fgets(cliente1.direccion, 100, stdin);
    printf("Ingrese el correo electrónico del cliente: ");
    fgets(cliente1.correo, 50, stdin);
    printf("Ingrese la cédula del cliente: ");
    fgets(cliente1.cedula, 11, stdin);
    size_t len = strlen(cliente1.cedula);
    if (cliente1.cedula[len - 1] == '\n') {
        cliente1.cedula[len - 1] = '\0';
    }
    
    if (validarCedula(cliente1.cedula)) {
        printf("\nLa cédula ingresada es válida.\n");
    } else {
        printf("\nLa cédula ingresada es inválida.\n");
    }

    // Mostrar la información del cliente
    printf("\n--Información del Cliente:--\n");
    printf("Nombre: %s", cliente1.nombre);
    printf("Teléfono: %s", cliente1.telefono);
    printf("Dirección: %s", cliente1.direccion);
    printf("Correo electrónico: %s", cliente1.correo);
    printf("Cédula: %s\n", cliente1.cedula);
    return 0;
}