#include "AFN2.h"

int main() 
{
	struct AFN_Automata *afn = Leer_AFN("ejemplo.afn");
	for(int i = 0; i < afn->no_estados; i++)
	{
		Imprimir_Estado(afn->estados[i]);
	}
	return 0;
}
