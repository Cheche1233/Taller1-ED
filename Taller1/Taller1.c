#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ListaSimple.h"

int main() {
    srand(time(NULL));

    ListaSimple *salon = crearLista();

    int numAlumnos = 5 + rand() % 36;
    printf("--------------------------------------\n");
    printf("Numero de alumnos iniciales: %d\n", numAlumnos);

    for (int i = 0; i < numAlumnos; i++) {
        int pos = rand() % (salon->size + 1);
        pushPos(salon, pos);
    }

    printf("Lista de alumnos despues de las altas:\n");
    printf("--------------------------------------\n");
    mostrarLista(salon);

    int numBajas = 3 + rand() % 13;
    printf("--------------------------------------\n");
    printf("Numero de alumnos que se daran de baja: %d\n", numBajas);

    for (int i = 0; i < numBajas && salon->size > 0; i++) {
        int posBaja = rand() % salon->size;
        borrarPos(salon, posBaja);
    }

    
    printf("Lista de alumnos despues de las bajas:\n");
    printf("--------------------------------------\n");
    mostrarLista(salon);

    liberarLista(salon);

    return 0;
}


