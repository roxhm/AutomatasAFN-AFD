#include <stdio.h> 
#include "Pila.h"

void Pila_Imprimir(Pila p)
{
	int i;
	for(i = 0; i < p -> top; i++)
	{
		printf(" %d ", p -> pila[i]);
	}
}

Pila Pila_Crear(int max_elementos)
{
	Pila p = malloc(sizeof(struct Pila)); 
	p -> max_elementos = max_elementos; 
	p -> pila = malloc(sizeof(int) * max_elementos); 
	p -> top = -1; 

	return p; 
}

void Pila_Empilar(Pila p, int elem)
{
	if(!Pila_estaLlena(p))
	{
		p -> top ++; 
		p -> pila[p -> top] = elem;
	}
	else 
	{
		printf("PILA LLENA: No se pueden insertar más elementos...\n");
		exit(1);
	} 
}

int Pila_Desempilar(Pila p)
{
	if(!Pila_estaVacia(p))
	{
		return p -> pila[p -> top --]; 
	}	
	else 
	{
		printf("PILA VACÍA: No existen elementos para quitar de la pila...\n"); 
		exit(1);
	}
}

bool Pila_estaVacia(Pila p)
{
	return p -> top == -1; 
}

bool Pila_estaLlena(Pila p)
{
	return p -> top == p -> max_elementos - 1; 
}

int Pila_ConsultarElemento(Pila p)
{
	return p -> pila[p -> top]; 
}

void Pila_Destruir(Pila p)
{
	free(p -> pila); 

	p -> pila = NULL; 
	p -> top = -1; 
	p -> max_elementos = 0;
}
