#include <stdio.h>
#include "funciones.h"

int menu() {
    int opc;
    printf("\n=== MENU BIBLIOTECA ===\n");
    printf("1. Registrar libro\n");
    printf("2. Mostrar libros\n");
    printf("3. Buscar libro\n");
    printf("4. Actualizar estado\n");
    printf("5. Eliminar libro\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opc);
    return opc;
}

int main() {
    struct Libro libros[10];
    int total = 0;
    int opc;

    do {
        opc = menu();
        switch (opc) {
            case 1:
                registrarLibro(libros, &total);
                break;
            case 2:
                mostrarLibros(libros, total);
                break;
            case 3:
                buscarLibro(libros, total);
                break;
            case 4:
                actualizarEstado(libros, total);
                break;
            case 5:
                eliminarLibro(libros, &total);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opc != 6);

    return 0;
}
