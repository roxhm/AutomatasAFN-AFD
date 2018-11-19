#pragma once
#include <stdbool.h> 
/*--------------------------------------------------------------------------*/
/* TAD: Cola                                                                */
/*--------------------------------------------------------------------------*/
/* ESTRUCTURAS DE DATOS                                                     */
/*--------------------------------------------------------------------------*/

typedef void* TipoC; 

struct TNodoCola
{
	TipoC info;
	struct TNodoCola* sig;
};

typedef struct TNodoCola* pNodoCola;

struct Cola
{
	pNodoCola primero, ultimo;
};

typedef struct Cola* Cola;

Cola Cola_Crear( void );
void Cola_Agregar( Cola col, TipoC elem );
void Cola_Eliminar ( Cola cola );
TipoC Cola_Consultar ( Cola col );
bool Cola_EsVacia ( Cola col );
void Cola_Destruir ( Cola col );
