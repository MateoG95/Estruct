#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Libro {
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[12]; // "Disponible" o "Prestado"
};

void registrarLibro(struct Libro libros[], int *total);
void mostrarLibros(struct Libro libros[], int total);
void buscarLibro(struct Libro libros[], int total);
void actualizarEstado(struct Libro libros[], int total);
void eliminarLibro(struct Libro libros[], int *total);
int menu();
