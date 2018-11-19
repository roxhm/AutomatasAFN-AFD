#pragma once
#include "Listas/lista.h"

typedef int64_t conjunto; 


struct AFN_Transicion
{
	char simbolo; 
	conjunto estados;
};

struct AFN_Estado
{
	int ID; 
	char es_final; 
	int num_transiciones; 
	AFN_Transicion *transiciones;  
	conjunto transiciones_epsilon; 
}; 

struct AFN
{
	struct AFN_Estado *estado_inicial; 
	int num_estados; 
	struct AFN_Estado *estados; 
};


