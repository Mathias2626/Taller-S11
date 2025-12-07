// biblioteca.h - Archivo de cabecera
#define MAX_TITULO 100
#define MAX_AUTOR 50
#define MAX_LIBROS 10

typedef struct {
    int id;
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int anio;
    char estado[15];
} Libro;

// Funciones
void agregarLibro(Libro libros[], int *total);
void mostrarLibros(Libro libros[], int total);
void buscarLibro(Libro libros[], int total);
void cambiarEstado(Libro libros[], int total);
void eliminarLibro(Libro libros[], int *total);
int idExiste(Libro libros[], int total, int id);