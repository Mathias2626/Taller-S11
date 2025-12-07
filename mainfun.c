// main.c - Programa principal
#include <stdio.h>
#include "biblioteca.h"

int main() {
    Libro libros[MAX_LIBROS];
    int total = 0;
    int opcion;
    printf("Sistema de biblioteca\n"); 
    do {
        printf("\nMenu\n");
        printf("1)Agregar libro\n");
        printf("2)Mostrar libros\n");
        printf("3)Buscar libro\n");
        printf("4)Cambiar estado\n");
        printf("5)Eliminar libro\n");
        printf("6)Salir\n");
        printf("Seleccione unaopción:");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1: agregarLibro(libros, &total);
            break;
            case 2: mostrarLibros(libros, total);
            break;
            case 3: buscarLibro(libros, total);
            break;
            case 4: cambiarEstado(libros, total);
            break;
            case 5: eliminarLibro(libros, &total);
            break;
            case 6: printf("Saliendo del programa\n"); 
            break;
            default: printf("Opción inválida\n");
        }
    } while(opcion != 6);
    
    return 0;
}

