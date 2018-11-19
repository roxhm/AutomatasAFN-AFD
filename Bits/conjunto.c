#include <stdio.h>
#include <stdbool.h>
#include "conjunto.h"

conjunto Conjunto_Vacio()
{
	return 0; 
}


conjunto Conjunto_Unitario(int elem)
{
	return 1lu << elem; 
}


conjunto Conjunto_Agregar(conjunto c, int elem)
{
	return Conjunto_Union(c, 1lu << elem); 
}


conjunto Conjunto_Union(conjunto a, conjunto b)
{
	return a | b; 
}


conjunto Conjunto_Eliminar(conjunto c, int elem)
{
	return c & (~(1lu << elem));
}


conjunto Conjunto_Interseccion(conjunto a, conjunto b)
{
	return a & b; 
}


conjunto Conjunto_Complemento(conjunto c)
{
	return ~c;
}

conjunto Conjunto_Diferencia(conjunto a, conjunto b)
{
	return a & (~b);
}


bool Conjunto_EsVacio(conjunto c)
{
	return c == 0; 
}


bool Conjunto_Pertenece(conjunto c, int elem)
{
	return c & (1lu << elem);
}


void Conjunto_Imprimir(conjunto c)
{
	unsigned long int u = 1; 
	int i; 

	for(i = 0; i < 64; i++)
	{	
		if(c & u)
			printf("%d ", i);
		u = u << 1;
	}
}

int Conjunto_ObtenerElemento(conjunto c)
{
	if(Conjunto_EsVacio(c))
		return -1;

	for(int i = 0; i < 64; i++)
		if(Conjunto_Pertenece(c, i))
			return i;
}








