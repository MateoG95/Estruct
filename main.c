#include "funciones.h"

int main() {
    struct Libro libros[10];
    int totalLibros = 0;
    int opcion;

    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                registrarLibro(libros, &totalLibros);
                break;
            case 2:
                mostrarLibros(libros, totalLibros);
                break;
            case 3:
                buscarLibro(libros, totalLibros);
                break;
            case 4:
                actualizarEstado(libros, totalLibros);
                break;
            case 5:
                eliminarLibro(libros, &totalLibros);
                break;
            case 6:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 6);

    return 0;
}
