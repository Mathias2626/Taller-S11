#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

void limpiarBuffer() {
    while (getchar() != '\n');
}

int idExiste(Libro libros[], int total, int id) {
    for (int i = 0; i < total; i++) {
        if (libros[i].id == id) return 1;
    }
    return 0;
}

void agregarLibro(Libro libros[], int *total) {
    if (*total >= MAX_LIBROS) {
        printf("No se pueden agregar más libros (máximo %d)\n", MAX_LIBROS);
        return;
    }
    
    Libro nuevo;
    
    // ID único
    do {
        printf("ID del libro: ");
        scanf("%d", &nuevo.id);
        limpiarBuffer();
        
        if (idExiste(libros, *total, nuevo.id)) {
            printf("ID ya existe. Use otro.\n");
        }
    } while (idExiste(libros, *total, nuevo.id));
    
    // Título
    printf("Título: ");
    fgets(nuevo.titulo, MAX_TITULO, stdin);
    nuevo.titulo[strlen(nuevo.titulo)-1] = '\0';
    
    // Autor
    printf("Autor: ");
    fgets(nuevo.autor, MAX_AUTOR, stdin);
    nuevo.autor[strlen(nuevo.autor)-1] = '\0';
    
    // Año
    printf("Año de publicación: ");
    scanf("%d", &nuevo.anio);
    limpiarBuffer();
    
    // Estado inicial
    strcpy(nuevo.estado, "Disponible");
    
    libros[*total] = nuevo;
    (*total)++;
    printf("Libro agregado exitosamente.\n\n");
}

void mostrarLibros(Libro libros[], int total) {
    if (total == 0) {
        printf("No hay libros registrados.\n");
        return;
    }
    
    printf("\nLista de libros\n");
    printf("ID  Titulo                    Autor              Año  Estado\n");
    
    for (int i = 0; i < total; i++) {
        printf("%-3d %-25s %-18s %-4d %s\n",
               libros[i].id,
               libros[i].titulo,
               libros[i].autor,
               libros[i].anio,
               libros[i].estado);
    }
    printf("\n");
}

void buscarLibro(Libro libros[], int total) {
    if (total == 0) {
        printf("No hay libros para buscar.\n");
        return;
    }
    
    int opcion;
    printf("Buscar por:\n1. ID\n2. Título\nOpción: ");
    scanf("%d", &opcion);
    limpiarBuffer();
    
    if (opcion == 1) {
        int id;
        printf("ID: ");
        scanf("%d", &id);
        limpiarBuffer();
        
        for (int i = 0; i < total; i++) {
            if (libros[i].id == id) {
                printf("\nID: %d\n", libros[i].id);
                printf("Título: %s\n", libros[i].titulo);
                printf("Autor: %s\n", libros[i].autor);
                printf("Año: %d\n", libros[i].anio);
                printf("Estado: %s\n", libros[i].estado);
                return;
            }
        }
        printf("Libro no encontrado.\n");
        
    } else if (opcion == 2) {
        char titulo[MAX_TITULO];
        printf("Título: ");
        fgets(titulo, MAX_TITULO, stdin);
        titulo[strlen(titulo)-1] = '\0';
        
        for (int i = 0; i < total; i++) {
            if (strstr(libros[i].titulo, titulo) != NULL) {
                printf("\nID: %d\n", libros[i].id);
                printf("Título: %s\n", libros[i].titulo);
                printf("Autor: %s\n", libros[i].autor);
                printf("Año: %d\n", libros[i].anio);
                printf("Estado: %s\n", libros[i].estado);
                return;
            }
        }
        printf("Libro no encontrado.\n");
    }
    printf("\n");
}
/*
strstr() - Buscar un texto Dentro de otro

Se usa para buscar si un texto aparece dentro de otro texto.

Si strstr() encuentra el texto, devuelve un puntero a donde lo encontró.
Si NO lo encuentra, devuelve NULL osea cero.
*/

void cambiarEstado(Libro libros[], int total) {
    if (total == 0) {
        printf("No hay libros para modificar.\n\n");
        return;
    }
    
    int id;
    printf("ID del libro: ");
    scanf("%d", &id);
    limpiarBuffer();
    
    for (int i = 0; i < total; i++) {
        if (libros[i].id == id) {
            printf("Estado actual: %s\n", libros[i].estado);
            
            if (strcmp(libros[i].estado, "Disponible") == 0) {
                strcpy(libros[i].estado, "Prestado");
            } else {
                strcpy(libros[i].estado, "Disponible");
            }
            
            printf("Nuevo estado: %s\n", libros[i].estado);
            return;
        }
    }
    printf("Libro no encontrado\n");
}

/*
strcpy() = Copiar texto
Se usa para copiar un texto en otro.
strcmp() = Comparar textos
Se usa para comparar si dos textos son iguales.
*/

void eliminarLibro(Libro libros[], int *total) {
    if (*total == 0) {
        printf("No hay libros para eliminar\n");
        return;
    }
    
    int id;
    printf("ID del libro a eliminar:");
    scanf("%d", &id);
    limpiarBuffer();
    
    for (int i = 0; i < *total; i++) {
        if (libros[i].id == id) {
            // Mover libros
            for (int j = i; j < *total - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (*total)--;
            printf("Libro eliminado.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n\n");
}

