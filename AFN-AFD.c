#include "AFN-AFD.h"
#include "Cola/Cola.h"

#include <stdlib.h>

struct ResultadoInsercion
{
	bool fue_nuevo;
	struct AFD_Estado* estado;
};

struct ResultadoInsercion Insertar(conjunto c, struct AFD* afd, struct AFN_Automata* afn)
{
	struct ResultadoInsercion resultado; 
	Lista i; 

	for(i = afd -> estados_afd; i != NULL; i = i -> siguiente)
	{
		if(((struct AFD_Estado*)(i -> dato)) -> estados_afn == c)
		{
			resultado.fue_nuevo = false; 
			resultado.estado = i -> dato;
			
			return resultado; 
		}	
	}

	struct AFD_Estado* estado = malloc(sizeof(struct AFD_Estado));
	if(Lista_EsVacia(afd -> estados_afd))
		estado -> id = 'A'; 
	else 
		estado -> id = ((struct AFD_Estado*)(Lista_Consultar(afd -> estados_afd))) -> id + 1;
	estado -> es_final = AFN_ConjuntoEsFinal(afn, c); 
	estado -> transiciones = Lista_Crear(); 
	estado -> estados_afn = c; 
	estado -> automata_contenedor = afd; 

	afd -> estados_afd = Lista_Agregar(afd -> estados_afd, estado); 

	resultado.fue_nuevo = true; 
	resultado.estado = estado; 

	return resultado; 	

}


conjunto AFN_TransicionarConjunto(conjunto estados_afn, char simbolo, struct AFN_Automata* afn)
{
	int i; 
	conjunto transiciones = Conjunto_Vacio(); 

	for(i = 0; i < afn -> no_estados; i++)
		if(Conjunto_Pertenece(estados_afn, i))
		{
			conjunto transicion = afn -> estados[i].transiciones[simbolo - afn -> alfabeto.caracter_min]; 
			transiciones = Conjunto_Union(transiciones, transicion); 
		}


	conjunto resultado = Conjunto_Vacio();

	for(i = 0; i < afn -> no_estados; i++)
		if(Conjunto_Pertenece(transiciones, i))
		{
			conjunto cerradura_epsilon = Cerradura_Epsilon(afn -> estados[i]); 
			resultado = Conjunto_Union(resultado, cerradura_epsilon);
		}

	return resultado; 
}

void AFD_AgregarTransicion(struct AFD_Estado* estado, char simbolo, struct AFD_Estado* estado_destino)
{
	struct Transicion* transicion = malloc(sizeof(struct Transicion));

	transicion -> simbolo = simbolo; 
	transicion -> estado_destino = estado_destino; 
	estado -> transiciones = Lista_Agregar(estado -> transiciones, transicion); 
}


struct AFD* ConvertirAFN(struct AFN_Automata* afn)
{
	Cola estados_por_transicionar = Cola_Crear(); 
	struct AFD* afd = malloc(sizeof(struct AFD));
	afd -> estado_inicial = 'A'; 
	afd -> estados_afd = Lista_Crear(); 

	struct ResultadoInsercion resultado; 
	resultado = Insertar(Cerradura_Epsilon2(afn -> estados[afn -> id_estado_inicial]), afd, afn); 

	Cola_Agregar(estados_por_transicionar, resultado.estado); 

	while(!Cola_EsVacia(estados_por_transicionar))
	{
		struct AFD_Estado* estado = Cola_Consultar(estados_por_transicionar);

		for(char simbolo = afn->alfabeto.caracter_min; simbolo <= afn->alfabeto.caracter_max; simbolo++)
		{
			conjunto c = AFN_TransicionarConjunto(estado -> estados_afn, simbolo, afn);
			if(!Conjunto_EsVacio(c))
			{

				resultado = Insertar(c, afd, afn);
				if(resultado.fue_nuevo)
				{
					Cola_Agregar(estados_por_transicionar, resultado.estado);
				}
				AFD_AgregarTransicion(estado, simbolo, resultado.estado);
			}
		}

		Cola_Eliminar(estados_por_transicionar);
	}

	return afd;
}

