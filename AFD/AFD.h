#pragma once 
#include <stdbool.h> 
#include "../Bits/conjunto.h" 
#include "../Lista/lista.h"

struct AFD; 
struct AFD_Estado;

struct Transicion
{
	char simbolo; 
	struct AFD_Estado *estado_destino; 
};


struct AFD_Estado 
{
	char id; 
	bool es_final;
       	Lista transiciones; 
	conjunto estados_afn; 
	struct AFD *automata_contenedor; 
};

struct AFD
{
	char estado_inicial; 
	Lista estados_afd;
};

void AFD_Imprimir(struct AFD*);
