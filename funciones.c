#include "funciones.h"

int menu() {
    int opcion;
    printf("\n--- MENU BIBLIOTECA ---\n");
    printf("1. Registrar libro\n");
    printf("2. Mostrar libros\n");
    printf("3. Buscar libro por ID o titulo\n");
    printf("4. Actualizar estado del libro\n");
    printf("5. Eliminar libro\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    getchar();
    return opcion;
}

void registrarLibro(struct Libro libros[], int *total) {
    if (*total >= 10) {
        printf("No se pueden registrar más libros.\n");
        return;
    }

    int idDuplicado = 0;
    printf("\n--- Registrar Libro ---\n");
    printf("ID (entero): ");
    scanf("%d", &libros[*total].id);
    getchar();

    for (int i = 0; i < *total; i++) {
        if (libros[i].id == libros[*total].id) {
            idDuplicado = 1;
            break;
        }
    }

    if (idDuplicado) {
        printf("El ID ya está registrado. Intente con otro.\n");
        return;
    }

    printf("Título: ");
    fgets(libros[*total].titulo, 100, stdin);
    libros[*total].titulo[strcspn(libros[*total].titulo, "\n")] = 0;

    printf("Autor: ");
    fgets(libros[*total].autor, 50, stdin);
    libros[*total].autor[strcspn(libros[*total].autor, "\n")] = 0;

    printf("Año de publicación: ");
    scanf("%d", &libros[*total].anio);
    getchar();

    strcpy(libros[*total].estado, "Disponible");
    (*total)++;
    printf("Libro registrado con éxito.\n");
}

void mostrarLibros(struct Libro libros[], int total) {
    if (total == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("\n%-5s | %-30s | %-20s | %-4s | %-10s\n", "ID", "Título", "Autor", "Año", "Estado");
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
    int idBuscar;
    char tituloBuscar[100];
    int opcion;

    printf("\n1. Buscar por ID\n2. Buscar por título\nSeleccione: ");
    scanf("%d", &opcion);
    getchar();

    if (opcion == 1) {
        printf("Ingrese el ID: ");
        scanf("%d", &idBuscar);
        getchar();
        for (int i = 0; i < total; i++) {
            if (libros[i].id == idBuscar) {
                printf("\nLibro encontrado:\nID: %d\nTítulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n",
                    libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
                return;
            }
        }
    } else if (opcion == 2) {
        printf("Ingrese el título: ");
        fgets(tituloBuscar, 100, stdin);
        tituloBuscar[strcspn(tituloBuscar, "\n")] = 0;
        for (int i = 0; i < total; i++) {
            if (strcmp(libros[i].titulo, tituloBuscar) == 0) {
                printf("\nLibro encontrado:\nID: %d\nTítulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n",
                    libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
                return;
            }
        }
    } else {
        printf("Opción inválida.\n");
        return;
    }

    printf("Libro no encontrado.\n");
}

void actualizarEstado(struct Libro libros[], int total) {
    int id;
    printf("\nIngrese el ID del libro: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < total; i++) {
        if (libros[i].id == id) {
            if (strcmp(libros[i].estado, "Disponible") == 0) {
                strcpy(libros[i].estado, "Prestado");
            } else {
                strcpy(libros[i].estado, "Disponible");
            }
            printf("Estado actualizado a '%s'.\n", libros[i].estado);
            return;
        }
    }

    printf("Libro no encontrado.\n");
}

void eliminarLibro(struct Libro libros[], int *total) {
    int id;
    printf("\nIngrese el ID del libro a eliminar: ");
    scanf("%d", &id);
    getchar();

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
