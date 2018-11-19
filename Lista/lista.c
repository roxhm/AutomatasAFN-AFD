#include <stdlib.h>
#include "lista.h"

Lista Lista_Crear()
{
	return NULL; 
}

Lista Lista_Agregar(Lista l, void* dato)
{
	Lista nuevo_nodo = malloc(sizeof(struct Lista)); 
	nuevo_nodo -> dato = dato; 
	nuevo_nodo -> siguiente = l; 

	return nuevo_nodo; 
}

Lista Lista_Eliminar(Lista l)
{
	Lista resto = l -> siguiente; 
	free(l); 

	return resto; 
}

bool Lista_EsVacia(Lista l)
{
	return l == NULL; 
}

void* Lista_Consultar(Lista l)
{
	return l -> dato; 
}

void Lista_Destruir(Lista l)
{
	while(!Lista_EsVacia(l))
		l = Lista_Eliminar(l);
}


