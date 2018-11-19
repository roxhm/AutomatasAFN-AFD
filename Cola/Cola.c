#include "Cola.h"

#include <stdlib.h>

/*--------------------------------------------------------------------------*/
/* OPERACIONES DEL TAD                                                      */
/*--------------------------------------------------------------------------*/

/* CONSTRUCTURA */
Cola Cola_Crear( void )
{
	Cola col = ( Cola ) malloc( sizeof( struct Cola ));
	col -> primero = col -> ultimo = NULL; 
	return col;
}

/* MODIFICADORAS */ 
void Cola_Agregar( Cola col, TipoC elem )
{
	pNodoCola p = ( pNodoCola )malloc( sizeof( struct TNodoCola )); 
	p -> info = elem; 
	p -> sig = NULL; 
	if ( col -> primero == NULL )
		col -> primero = col -> ultimo = p;
	else
	{
		col -> ultimo -> sig =  p; 
		col -> ultimo = p; 
	}
}

void Cola_Eliminar ( Cola cola )
{
       	pNodoCola p;
	 if(Cola_EsVacia(cola))
		 return;
	 else
	 {
		 if( cola -> primero -> sig == NULL )
		 {
			 free( cola -> primero );
			 cola -> primero = cola -> ultimo = NULL;
		 }
		 else
		 {
			 p = cola -> primero;
			 cola -> primero = p -> sig;
			 free( p );
		 }
	 }
}


/* OBSERVADORAS */
TipoC Cola_Consultar ( Cola col )
{
	return col -> primero -> info; 
}

bool Cola_EsVacia ( Cola col )
{
	return col -> primero == NULL; 
}

/* DESTRUCTORAS */ 
void Cola_Destruir ( Cola col )
{
	pNodoCola p, q; 
	for( p = col -> primero; p != NULL; p = p->sig, free( q ) )
	{
		q = p; 
	}
	free(col); 
}
