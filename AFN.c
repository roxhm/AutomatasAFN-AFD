#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "AFN.h"
#include "Pila/Pila.h"

bool Estado_EsRecorrido(struct AFN_Estado estado, bool *ptrLeido);

struct Info_Archivo
{
	int estado_inicial;
       	int no_estados; 	
	int no_estados_finales; 
	unsigned char caracter_min; 
	unsigned char caracter_max; 
};

int Rango_Alfabeto (struct AFN_Alfabeto alfabeto)
{
	return alfabeto.caracter_max - alfabeto.caracter_min + 1; 
}
	
void Imprimir_Conjunto(conjunto c)
{
	putchar('{');
	for(unsigned i = 0; i < 64; i++)
	{
		if(Conjunto_Pertenece(c, i))
			printf("%u ", i + 1);
	}
	putchar('}');
}

void Imprimir_Estado(struct AFN_Estado estado)
{
	printf("ESTADO \n");
	printf("\tid = %d\n", estado.id + 1);
	printf("\t%s\n", estado.es_final? "es final" : "no es final");
	int no_transiciones = Rango_Alfabeto(estado.automata_contenedor->alfabeto);
	for(int i = 0; i < no_transiciones; i++)
	{
		char simbolo_trans = i + estado.automata_contenedor->alfabeto.caracter_min;
		printf("\t%c -> ", simbolo_trans);
		Imprimir_Conjunto(estado.transiciones[i]);
		printf("\n");
	}
	printf("\ttransiciones epsilon: ");
	Imprimir_Conjunto(estado.transiciones_epsilon);
	printf("\n");
}

struct Info_Archivo Obtener_Info(FILE *archivo_afn)
{
	struct Info_Archivo info = {
		.estado_inicial = 0,
	       	.no_estados = 0,
		.no_estados_finales = 0, 
		.caracter_min = '\0',
		.caracter_max = '\0'
	};

	char caracter; 

	fscanf(archivo_afn, "%d", &info.estado_inicial); 
	info.no_estados = info.estado_inicial;
	info.estado_inicial --;

	while(caracter != '\n')
	{
		int estado_final; 

		fscanf(archivo_afn, " %d", &estado_final); 
		caracter = fgetc(archivo_afn);
	       	info.no_estados_finales ++;	
	}

	info.caracter_min = 255;
	info.caracter_max = 0;
	
	// Ciclo que empieza y se rompe únicamente cuando se llega al fin
	// de archivo. El fin de archivo está dado por la función fscanf. 
	// No lo hicimos capturando cada caracter hasta terminar de leer
	// el archivo porque sería complicado estar interpretando cada vez 
	// el caracter leído. 

	while(true)
	{
		int estado_fuente, estado_destino;
		unsigned char simbolo[8];
		if(fscanf(archivo_afn, " %d %s %d", 
			&estado_fuente, 
			simbolo, 
			&estado_destino) == EOF)
			break;

		if(estado_fuente > info.no_estados)
			info.no_estados = estado_fuente; 
		if(estado_destino > info.no_estados)
			info.no_estados = estado_destino;

		if(strcmp(simbolo, "epsilon") != 0)
		{
			if(simbolo[0] > info.caracter_max)
				info.caracter_max = simbolo[0]; 
			if(simbolo[0] < info.caracter_min)
				info.caracter_min = simbolo[0]; 
		}
	}
	rewind(archivo_afn); 

	return info;
}


struct AFN_Automata* Leer_AFN (char *nombre_archivo)
{
	struct AFN_Automata *afn = malloc(sizeof(struct AFN_Automata)); 

	FILE *archivo_afn = fopen(nombre_archivo, "r"); 

	if(archivo_afn == NULL) 
	{
		perror("No se pudo abrir el archivo");
		exit(1);
	}

	struct Info_Archivo info = Obtener_Info(archivo_afn);
	
	afn->id_estado_inicial = info.estado_inicial;
	afn->no_estados = info.no_estados; 
	afn->alfabeto.caracter_min = info.caracter_min; 
	afn->alfabeto.caracter_max = info.caracter_max; 

	afn->estados = malloc(sizeof(struct AFN_Estado) * afn->no_estados);

	int i; 

	for(i = 0; i < info.no_estados; i++)
	{
		afn->estados[i].id = i;
		afn->estados[i].es_final = false;
		afn->estados[i].transiciones = malloc(sizeof(conjunto)
		  * (Rango_Alfabeto(afn->alfabeto)));


		  for(int j = 0; j < Rango_Alfabeto(afn->alfabeto); j++)
			afn->estados[i].transiciones[j] =
			Conjunto_Vacio();

		afn->estados[i].transiciones_epsilon = Conjunto_Vacio();
		afn->estados[i].automata_contenedor = afn; 
	}

	int estado_inicial;
	fscanf(archivo_afn, "%d", &estado_inicial);

	int estado_final;
	
	for(i = 0; i < info.no_estados_finales; i++)
	{
		fscanf(archivo_afn, " %d", &estado_final); 
		estado_final --; 

		afn->estados[estado_final].es_final = true; 
	}

	int estado_fuente;
	char simbolo_transicion[8]; 
	int estado_destino; 

	while(true)
	{
		if(fscanf(archivo_afn, " %d %s %d", &estado_fuente,
			simbolo_transicion, &estado_destino) == EOF)
		       break;

		estado_fuente--; 
		estado_destino--;

		if(strcmp(simbolo_transicion, "epsilon") == 0)
			afn->estados[estado_fuente].transiciones_epsilon =
			Conjunto_Agregar(afn->estados[estado_fuente].
			transiciones_epsilon, estado_destino);
		else
		afn->estados[estado_fuente].
		transiciones[simbolo_transicion[0] - info.caracter_min] =
		Conjunto_Agregar(afn->estados[estado_fuente].
			transiciones[simbolo_transicion[0] - info.caracter_min],
			estado_destino); 
	}

	rewind(archivo_afn); 

	return afn;
}



conjunto Cerradura_Epsilon(struct AFN_Estado estado)
{
	conjunto resultado = Conjunto_Vacio(); 
	bool leido[estado.automata_contenedor -> no_estados];
	memset(leido, 0, estado.automata_contenedor -> no_estados * sizeof(bool));
	Pila estados_por_recorrer = Pila_Crear(estado.automata_contenedor -> no_estados); 

	Pila_Empilar(estados_por_recorrer, estado.id);
	leido[estado.id] = 1;
	resultado = Conjunto_Agregar(resultado, estado.id);

	while(!Pila_estaVacia(estados_por_recorrer))
	{
		struct AFN_Estado estado_top = estado.automata_contenedor -> estados[Pila_ConsultarElemento(estados_por_recorrer)]; 

			if(Conjunto_EsVacio(estado_top.transiciones_epsilon) || Estado_EsRecorrido(estado_top, leido))
			{
				Pila_Desempilar(estados_por_recorrer); 
			}
			else
			{
				int i; 
				bool he_encontrado_noleido = false;
				for(i = 0; i < estado.automata_contenedor -> no_estados && !he_encontrado_noleido; i++)
					if(Conjunto_Pertenece(estado_top.transiciones_epsilon, i) && leido[i] == 0)
					{
						Pila_Empilar(estados_por_recorrer, i); 
						leido[i] = 1; 
						resultado = Conjunto_Agregar(resultado, i);
						he_encontrado_noleido = true;
					}
			}
	}

       	return resultado;
}

bool Estado_EsRecorrido(struct AFN_Estado estado, bool *ptrLeido)
{
	int i; 
	for(i = 0; i < estado.automata_contenedor -> no_estados; i++)
	{
		if((Conjunto_Pertenece(estado.transiciones_epsilon, i) && ptrLeido[i] == 0))
			return 0; 
	}

	return 1; 
}

conjunto Cerradura_Epsilon2(struct AFN_Estado estado)
{
	conjunto leido = Conjunto_Vacio();  
	Pila estados_por_recorrer = Pila_Crear(estado.automata_contenedor -> no_estados); 

	Pila_Empilar(estados_por_recorrer, estado.id);
	leido = Conjunto_Agregar(leido, estado.id);

	while(!Pila_estaVacia(estados_por_recorrer))
	{
		struct AFN_Estado estado_top = estado.automata_contenedor -> estados[Pila_ConsultarElemento(estados_por_recorrer)]; 
		conjunto diferencia = Conjunto_Diferencia(estado_top.transiciones_epsilon, leido);

		if(Conjunto_EsVacio(diferencia))
			Pila_Desempilar(estados_por_recorrer); 
		else 
		{
			int elemento = Conjunto_ObtenerElemento(diferencia);
			
			Pila_Empilar(estados_por_recorrer, elemento);
			leido = Conjunto_Agregar(leido, elemento);
		}
	}

	return leido; 
}

bool AFN_ConjuntoEsFinal(struct AFN_Automata* afn, conjunto c)
{
	int i; 

	for(i = 0; i < afn -> no_estados; i++)
		if(Conjunto_Pertenece(c, i) && afn -> estados[i].es_final)
			return true; 
	return false; 
}

