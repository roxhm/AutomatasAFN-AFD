#pragma once

#include <inttypes.h>

typedef int64_t conjunto_xbits;

struct nodo_arbol 
{
	struct nodo_arbol *nodo_derecho, *nodo_izquierdo; 
	void *ptr_dato;
};

struct nodo_arbol* Arbol_Vacio(); 

struct nodo_arbol* Arbol_Insertar(struct nodo_arbol *arbol, void *dato, int (*comparar)(void*, void*));
	
/* 
 * Busca el _dato_ en el _arbol_ y retorna un puntero a él si está
 * y NULL en caso de que no esté.
 *
 * Recibe: 
 * 	arbol = puntero al nodo del arbol desde el cuál se iniciará la búsqueda.
 * 	dato = dato por buscar.
 * 	comparar = función de comparación entre datos.
 *
 * Retorna: 
 * 	El puntero al dato que, de acuerdo a la función de comparación 'comparar'
 * 	es igual al dato dado. En caso de que no haya tal dato, NULL.
 *
 */
void* Arbol_Buscar(struct nodo_arbol *arbol, void* dato, int (*comparar)(void*, void*));

/*
 * Verifica si el _dato_ se encuentra en el _arbol_. Retorna 1 si está, 0 si no. 
 */
int Arbol_Contiene(struct nodo_arbol *arbol, void* dato, int (*comparar)(void*, void*));

