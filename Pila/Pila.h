// P I L A 
// Pila de números enteros implementada con un arreglo. 

#pragma once
#include <stdlib.h> 
#include <stdbool.h> 

struct Pila
{
	int *pila; 
	int top; 
	int max_elementos; 
}; 

typedef struct Pila* Pila; 

// P R O T O T I P O S
//
// CONSTRUCTORAS
//
Pila Pila_Crear(int); 
//
// MODIFICADORAS
//
void Pila_Empilar(Pila, int);
int Pila_Desempilar(Pila); 
//
// OBSERVADORAS
//
bool Pila_estaVacia(Pila); 
bool Pila_estaLlena(Pila); 
//
// DE CONSULTA
//
int Pila_ConsultarElemento(Pila); 
// 
// DESTRUCTORAS
//
void Pila_Destruir(Pila); 

//
// PROCEDIMIENTOS K PROCD?
//
void Pila_Imprimir(Pila p);



