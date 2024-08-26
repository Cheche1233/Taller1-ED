#pragma once

typedef struct Alumno{
    char nombre[50];
    char apellido[50];
    int semestre;

}Alumno;


typedef struct Nodo{
    struct Alumno *alumno;
    char letra;
    struct Nodo *sig;

}Nodo;

typedef struct Lista{
    Nodo *head;
    Nodo *tail;
    Nodo *current;
    int size;

}ListaSimple;

Nodo* crearNodo();
ListaSimple* crearLista();
void pushFront(ListaSimple *lista);
void pushBack(ListaSimple *lista);
void pushPos(ListaSimple *lista, int pos);
Nodo* buscarNodo(ListaSimple *lista, int pos);
void printNodo(Nodo *nodo);
void mostrarLista(ListaSimple *lista);
void liberarNodo(Nodo *nodo);
void liberarLista(ListaSimple *lista);
int borrarPos(ListaSimple *lista, int pos);
Alumno* crearAlumno();
