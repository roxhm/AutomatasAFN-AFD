#include "AFD.h"

#include <stdlib.h>
#include <stdio.h>

void AFD_Imprimir(struct AFD* afd)
{
	Lista i;
	for(i = afd -> estados_afd; i != NULL; i = i -> siguiente)
	{
		struct AFD_Estado* estado = i -> dato;

		printf("ESTADO\n");
		printf("\tid = %c\n", estado -> id);
		printf("\t%s\n", estado -> es_final ? "es final" : "no es final");
		printf("\testados_afn = ");
		Conjunto_Imprimir(estado -> estados_afn);
		printf("\n");

		Lista j;
		for(j = estado -> transiciones; j != NULL; j = j -> siguiente)
		{
			struct Transicion* transicion = j -> dato;
			printf(" %c -> %c\n",
				transicion -> simbolo, 
				transicion -> estado_destino -> id);
		}
		printf("\n");
	}
}
