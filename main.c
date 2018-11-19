#include <stdio.h> 
#include <string.h> 
#include "AFN.h"
#include "AFD/AFD.h"
#include "Pila/Pila.h"
#include "AFN-AFD.h"

void ImprimirAyuda();

int main(int no_argumentos, char* arreglo_de_argumentos[])
{
	if(no_argumentos == 1)
	{
		ImprimirAyuda();
		exit(-1);
	}

	struct AFN_Automata *afn = Leer_AFN(arreglo_de_argumentos[1]);
	for(int i = 0; i < afn -> no_estados; i++)
	{
		Imprimir_Estado(afn -> estados[i]);
	}


	printf("\n"); 
	Conjunto_Imprimir(Cerradura_Epsilon(afn -> estados[0]));

	printf("\n"); 
	Conjunto_Imprimir(Cerradura_Epsilon2(afn -> estados[0]));

	struct AFD* afd = ConvertirAFN(afn);
	
	printf("\n");
	AFD_Imprimir(afd);
	
	return 0;
}

void ImprimirAyuda()
{
	printf("Uso: ./a.out <nombre de archivo .afn>\n");
}

