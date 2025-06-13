#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"

void registrarLibro(struct Libro libros[], int *total) {
    if (*total >= 10) {
        printf("No se pueden registrar mas de 10 libros.\n");
        return;
    }

    int id;
    printf("Ingrese ID del libro: ");
    while (scanf("%d", &id) != 1) {
        printf("Entrada invalida. Ingrese un numero entero para el ID: ");
        fflush(stdin);
    }

    for (int i = 0; i < *total; i++) {
        if (libros[i].id == id) {
            printf("Ya existe un libro con ese ID.\n");
            return;
        }
    }

    libros[*total].id = id;
    fflush(stdin);

    printf("Ingrese titulo del libro: ");
    fgets(libros[*total].titulo, 100, stdin);
    libros[*total].titulo[strcspn(libros[*total].titulo, "\n")] = '\0';

    printf("Ingrese autor del libro: ");
    fgets(libros[*total].autor, 50, stdin);
    libros[*total].autor[strcspn(libros[*total].autor, "\n")] = '\0';

    do {
        printf("Ingrese AA de publicacion (4 digitos): ");
        if (scanf("%d", &libros[*total].anio) != 1 || libros[*total].anio < 1000 || libros[*total].anio > 9999) {
            printf("Anio invalido. Intente nuevamente.\n");
            fflush(stdin);
        } else {
            break;
        }
    } while (1);

    strcpy(libros[*total].estado, "Disponible");
    (*total)++;
    printf("Libro registrado exitosamente.\n");
}

void mostrarLibros(struct Libro libros[], int total) {
    printf("\n%-5s | %-30s | %-20s | %-4s | %-10s\n", "ID", "Titulo", "Autor", "AA", "Estado");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("%-5d | %-30s | %-20s | %-4d | %-10s\n",
               libros[i].id,
               libros[i].titulo,
               libros[i].autor,
               libros[i].anio,
               libros[i].estado);
    }
}

void buscarLibro(struct Libro libros[], int total) {
    int opcion;
    do {
        printf("Buscar libro por:\n1. ID\n2. Titulo\nSeleccione una opcion: ");
        if (scanf("%d", &opcion) != 1) {
            fflush(stdin);
            printf("Entrada invalida.\n");
            continue;
        }

        if (opcion == 1) {
            int id;
            printf("Ingrese ID del libro: ");
            scanf("%d", &id);
            for (int i = 0; i < total; i++) {
                if (libros[i].id == id) {
                    printf("Libro encontrado:\n");
                    printf("Titulo: %s\nAutor: %s\nAA: %d\nEstado: %s\n",
                           libros[i].titulo,
                           libros[i].autor,
                           libros[i].anio,
                           libros[i].estado);
                    return;
                }
            }
            printf("No se encontro libro con ese ID.\n");
            return;

        } else if (opcion == 2) {
            char titulo[100];
            fflush(stdin);
            printf("Ingrese titulo: ");
            fgets(titulo, 100, stdin);
            titulo[strcspn(titulo, "\n")] = '\0';

            for (int i = 0; i < total; i++) {
                if (strcmp(libros[i].titulo, titulo) == 0) {
                    printf("Libro encontrado:\n");
                    printf("ID: %d\nAutor: %s\nAnio: %d\nEstado: %s\n",
                           libros[i].id,
                           libros[i].autor,
                           libros[i].anio,
                           libros[i].estado);
                    return;
                }
            }
            printf("No se encontro libro con ese titulo.\n");
            return;
        } else {
            printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (1);
}

void actualizarEstado(struct Libro libros[], int total) {
    int id;
    printf("Ingrese ID del libro a actualizar: ");
    scanf("%d", &id);
    for (int i = 0; i < total; i++) {
        if (libros[i].id == id) {
            if (strcmp(libros[i].estado, "Disponible") == 0) {
                strcpy(libros[i].estado, "Prestado");
            } else {
                strcpy(libros[i].estado, "Disponible");
            }
            printf("Estado actualizado a: %s\n", libros[i].estado);
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

void eliminarLibro(struct Libro libros[], int *total) {
    int id;
    printf("Ingrese ID del libro a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < *total; i++) {
        if (libros[i].id == id) {
            for (int j = i; j < *total - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (*total)--;
            printf("Libro eliminado correctamente.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}
