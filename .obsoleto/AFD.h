#pragma once
#include"Listas/lista.h"

struct AFD_Transicion 
{
	char simbolo;
	conjunto estados;
};

struct AFD_Estado{
	int ID; 
	char es_final; 
	lista transiciones;
	conjunto conjunto_estados; 
	char recorrido; 
};

struct AFD
{
	struct EstadoAFD *AFD_estado_inicial;
}; 
