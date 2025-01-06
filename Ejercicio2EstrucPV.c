#include <stdio.h>

//Ejercicio 2 P3 Guillermo Vaca (Gestion de productos de venta)

struct Producto {
    char nombre[50];
    int codigo;
    float precio;
    int cantidad;
};

int main() {
    struct Producto productos[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        scanf("%s", productos[i].nombre);
        printf("Ingrese el cC3digo del producto %d: ", i + 1);
        scanf("%d", &productos[i].codigo);
        printf("Ingrese el precio del producto %d: ", i + 1);
        scanf("%f", &productos[i].precio);
        printf("Ingrese la cantidad del producto %d: ", i + 1);
        scanf("%d", &productos[i].cantidad);
    }

    printf("\nInformaciC3n de los Productos:\n");
    for (i = 0; i < 3; i++) {
        printf("Producto %d:\n", i + 1);
        printf("Nombre: %s\n", productos[i].nombre);
        printf("CC3digo: %d\n", productos[i].codigo);
        printf("Precio: %.2f\n", productos[i].precio);
        printf("Cantidad: %d\n", productos[i].cantidad);
    }

    return 0;
}