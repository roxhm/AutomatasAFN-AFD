#pragma once 
#include <stdbool.h>

struct Lista
{
	void* dato; 
	struct Lista *siguiente; 
}; 

typedef struct Lista* Lista;

//
// CONSTRUCTORAS
//

Lista Lista_Crear();

//
// MODIFICADORAS
//

Lista Lista_Agregar(Lista, void*);
Lista Lista_Eliminar(Lista); 

//
// OBSERVADORAS
//

bool Lista_EsVacia(Lista); 
void* Lista_Consultar(Lista); 

//
// DESTRUCTORAS
//

void Lista_Destruir(Lista); 


