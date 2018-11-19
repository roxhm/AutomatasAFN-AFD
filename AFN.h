#pragma once 
#include <stdbool.h> 
#include "Bits/conjunto.h"

struct AFN_Automata;

struct AFN_Estado
{
	int id; 
	bool es_final;
	conjunto *transiciones;
	conjunto transiciones_epsilon;
	struct AFN_Automata *automata_contenedor;
};

struct AFN_Alfabeto
{
	char caracter_min; 
	char caracter_max;
}; 

struct AFN_Automata
{
	int id_estado_inicial; 
	int no_estados; 
	struct AFN_Alfabeto alfabeto; 
	struct AFN_Estado *estados; 
}; 

// P R O T O T I P O S

/* Lee un AFN de un archivo */ 
struct AFN_Automata* Leer_AFN (char *nombre_archivo);

/* Obtiene el rango de un alfabeto */ 
int Rango_Alfabeto (struct AFN_Alfabeto); 

void Imprimir_Estado(struct AFN_Estado);

conjunto Cerradura_Epsilon(struct AFN_Estado); 
conjunto Cerradura_Epsilon2(struct AFN_Estado);

bool AFN_ConjuntoEsFinal(struct AFN_Automata*, conjunto); 
