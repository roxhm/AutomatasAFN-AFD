#include <stdio.h> 
#include "Pila.h"

int main()
{
	Pila mipila = Pila_Crear(6); 
	int i, elem; 

	for(i = 0; i <= 6; i++)
		Pila_Empilar(mipila, i);

//	for(i = 0; i <= 6; i++)
//		elem = Pila_Desempilar(mipila); 

	printf("Primer elemento de la pila: %d\n", Pila_ConsultarElemento(mipila));
	Pila_Destruir(mipila); 

	return 0;
}
