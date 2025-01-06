#include <stdio.h>
#include <string.h>

//Ejercicio 7 P3 Guillermo Vaca (Verificador de Cedula)

int validarCedula(const char *cedula) {
    int longitud = strlen(cedula);
    if (longitud != 10) {
        return 0; 
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
    char cedula[11];
    printf("Ingrese la cédula (10 dígitos): ");
    scanf("%10s", cedula);
    if (validarCedula(cedula)) {
        printf("La cédula es válida.\n");
    } else {
        printf("La cédula es inválida.\n");
    }
    return 0;
}