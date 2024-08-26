#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaSimple.h"


Nodo* crearNodo() {
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->letra = '\0';
    nodo->sig = NULL;

    return nodo;
}

Alumno* crearAlumno() {
    Alumno *alumno = (Alumno*)malloc(sizeof(Alumno));

    for(int i = 0; i < 14; i++) {
        alumno->nombre[i] = 'a' + rand() % 26;
        alumno->apellido[i] = 'a' + rand() % 26;
    }
    alumno->nombre[14] = '\0';
    alumno->apellido[14] = '\0';

    alumno->semestre = rand() % 7 + 1;

    return alumno;
}


ListaSimple* crearLista() {
    ListaSimple *lista = (ListaSimple*)malloc(sizeof(ListaSimple));
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;
    lista->size = 0;
    return lista;
}

void pushFront(ListaSimple *lista) {
    Nodo *nodo = crearNodo();
    Alumno *alumno = crearAlumno();
    nodo->alumno = alumno;

    if(lista->head == NULL) {
        lista->tail = nodo;
        nodo->sig = NULL;
    } else {
        nodo->sig = lista->head;
    }
    lista->head = nodo;
    lista->size++;
}

void pushBack(ListaSimple *lista) {
    Nodo *nodo = crearNodo();
    Alumno *alumno = crearAlumno();
    nodo->alumno = alumno;
    if(lista->tail == NULL) {
        lista->head = nodo;
        nodo->sig = NULL;
    } else {
        lista->tail->sig = nodo;
        nodo->sig = NULL;
    }
    lista->tail = nodo;
    lista->size++;
}

void pushPos(ListaSimple *lista, int pos) {
    if(pos == 0) {
        pushFront(lista);
        return;
    } else if(lista->size == pos) {
        pushBack(lista);
        return;
    } else {
        Nodo *nodo = crearNodo();
        Alumno *alumno = crearAlumno();
        nodo->alumno = alumno;
        Nodo *ant = buscarNodo(lista, pos-1);
        if (ant != NULL) {
            nodo->sig = ant->sig;
            ant->sig = nodo;
            lista->size++;
        }
    }
}

Nodo* buscarNodo(ListaSimple *lista, int pos) {
    if (pos < 0 || pos >= lista->size) {
        return NULL;
    }

    Nodo *actual = lista->head;

    for (int i = 0; i < pos; i++) {
        actual = actual->sig;
    }

    return actual;
}

void printNodo(Nodo *nodo) {
    if (nodo != NULL) {
        printf("Nombre Alumno: %s\n", nodo->alumno->nombre);
        printf("Apellido Alumno: %s\n", nodo->alumno->apellido);
        printf("Semestre Alumno: %d\n", nodo->alumno->semestre);
        printf("        |       \n");
        printf("        v       \n");
    }
}

void mostrarLista(ListaSimple *lista) {
    lista->current = lista->head;
    while (lista->current != NULL) {
        printNodo(lista->current);
        lista->current = lista->current->sig;
    }
    printf("\n");
}

void liberarNodo(Nodo *nodo) {
    if (nodo != NULL) {
        free(nodo->alumno);
        free(nodo);
    }
}

void liberarLista(ListaSimple *lista) {
    Nodo *current = lista->head;
    Nodo *siguiente;

    while (current != NULL) {
        siguiente = current->sig;
        liberarNodo(current);
        current = siguiente;
    }
    
    free(lista);
}

int borrarPos(ListaSimple *lista, int pos){
    if(pos == 0){
        Nodo *temp = lista->head->sig;
        free(lista->head);
        lista->head = temp;
        lista->size--;
        return 1;
    }
    Nodo *temp1;
    temp1 = buscarNodo(lista, pos-1);
    Nodo *nodoAborrar = buscarNodo(lista, pos);
    temp1->sig = nodoAborrar->sig;
    liberarNodo(nodoAborrar);
    if(pos == lista->size-1){
        lista->tail = temp1;
    }
    lista->size--;
    return 1;
}
