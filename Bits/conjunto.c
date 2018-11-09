#include <stdbool.h>
#include "conjunto.h"

conjunto Conjunto_Vacio()
{
	return 0; 
}


conjunto Conjunto_Unitario(int elem)
{
	return 1 << elem; 
}


conjunto Conjunto_Agregar(conjunto c, int elem)
{
	return Conjunto_Union(c, 1 << elem); 
}


conjunto Conjunto_Union(conjunto a, conjunto b)
{
	return a | b; 
}


conjunto Conjunto_Eliminar(conjunto c, int elem)
{
	return c & (~(1 << elem));
}


conjunto Conjunto_Interseccion(conjunto a, conjunto b)
{
	return a & b; 
}


conjunto Conjunto_Complemento(conjunto c)
{
	return ~c;
}


bool Conjunto_EsVacio(conjunto c)
{
	return c == 0; 
}


bool Conjunto_Pertenece(conjunto c, int elem)
{
	return c & (1 << elem);
}
