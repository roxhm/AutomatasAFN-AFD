#include "Conjuntos.h"

struct nodo_arbol* Arbol_Vacio()
{
	return NULL; 
}

struct nodo_arbol* Arbol_Insertar(struct nodo_arbol *arbol, void *dato, int (*comparar)(void*, void*))
{
	int comparacion; 
	if(arbol == NULL)
	{	
		struct nodo_arbol *nuevo_nodo = malloc(sizeof(*nuevo_nodo));
		nuevo_nodo -> nodo_izquierdo = NULL; 
		nuevo_nodo -> nodo_derecho = NULL; 
		nuevo_nodo -> ptr_dato = dato; 

		return nuevo_nodo; 
	}

	comparacion = comparar(arbol -> ptr_dato, dato);
	
	if(comparacion == 0)
		return arbol; 
	else if(comparacion > 0)
		arbol -> nodo_derecho = Arbol_Insertar(arbol -> nodo_derecho, dato, comparar); 
	else
		arbol -> nodo_izquierdo = Arbol_Insertar(arbol -> nodo_izquierdo, dato, comparar); 

	return arbol; 
}


void* Arbol_Buscar(struct nodo_arbol *arbol, void* dato, int (*comparar)(void*, void*))
{
	int comparacion;

	if(arbol == NULL) 
		return NULL;
	
	comparacion = comparar(arbol -> ptr_dato, dato); 

	if(comparacion == 0) 
		return arbol -> ptr_dato; 
	else if(comparacion > 0) 
		return Arbol_Buscar(arbol -> nodo_derecho, dato, comparar); 
	else 
		return Arbol_Buscar(arbol -> nodo_izquierdo, dato, comparar); 
}



int Arbol_Contiene(struct nodo_arbol *arbol, void* dato, int (*comparar)(void*, void*))
{
	return Arbol_Buscar(arbol, dato, comparar) != NULL;
}
