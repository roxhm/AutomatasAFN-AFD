#pragma once
// Conjunto de números enteros en el rango [0 - 63]. 
// Elemento:
// 	Número entero dentro del rango 0 - 63. 

#include <stdbool.h>

typedef unsigned long int conjunto; 

// P R O T O T I P O S //


// CONSTRUCTORAS


/* Crea un conjunto vacío.
 * Parámetros:
 * 	 Ninguno. 
 * Retorno:
 * 	 Conjunto vacío. 
 */ 
conjunto Conjunto_Vacio();


/* Crea un conjunto con un sólo elemento dado.
 * Parámetros: 
 * 	El elemento a agregar. 
 * Retorno: 
 * 	Conjunto con el elemento agregado. 
 */
conjunto Conjunto_Unitario(int elem); 


// MODIFICADORAS


/* Agrega un elemento a un conjunto en caso de que no se encuentre ya en el conjunto. 
 * Parámetros:
 * 	 El conjunto al que se desea agregar el elemento. 
 * 	 El elemento a agregar. 
 * Retorno: 
 * 	Conjunto con el elemento ya insertado. 
 */
conjunto Conjunto_Agregar(conjunto, int); 


/* Elimina un elemento de un conjunto. 
 * Parámetros: 
 * 	El conjunto del que se desea eliminar el elemento. 
 * 	El elemento a eliminar. 
 * Retorno: 
 * 	Conjunto sin el elemento. 
 */
conjunto Conjunto_Eliminar(conjunto, int);


// OBSERVADORAS 


/* Verifica si un conjunto es vacío. 
 * Parámetros: 
 * 	El conjunto del que se desea saber si es vacío o no. 
 * Retorno: 
 * 	1 si es vacío. 
 * 	0 si no es vacío. 
 */
bool Conjunto_EsVacio(conjunto); 


/* Verifica si un elemento pertenece al conjunto. 
 * Parámetros: 
 * 	El conjunto en el que se verificará la existencia del elemento. 
 * 	El elemento a buscar en el conjunto. 
 * Retorno: 
 * 	1 si el elemento pertenece al conjunto. 
 * 	0 si el elemento no pertenece al conjunto. 
 */
bool Conjunto_Pertenece(conjunto, int);


// OPERACIONES ENTRE CONJUNTOS


/* Une dos conjuntos. 
 * Parámetros: 
 * 	Conjunto a. 
 * 	Conjunto b.
 * Retorno: 
 * 	Conjunto formado por los elementos del conjunto a y los elementos del conjunto b.  
 */
conjunto Conjunto_Union(conjunto, conjunto); 


/* Intersecta dos conjuntos. 
 * Parámetros: 
 * 	Conjunto a. 
 * 	Conjunto b. 
 * Retorno: 
 * 	Conjunto formado por los elementos que están en el conjunto a y a su vez en el conjunto b. 
 */
conjunto Conjunto_Interseccion(conjunto, conjunto); 


/* Obtiene el conjunto complemento de otro conjunto. 
 * Parámetros: 
 *	El conjunto (c) del que se obtendrá el conjunto complemento. 
 * Retorno: 
 *      Conjunto formado por los elementos que no están en el conjunto c. 
 */
conjunto Conjunto_Complemento(conjunto);


/* Obtiene el conjunto diferencia entre dos conjuntos. 
 * Parámetros: 
 * 	Conjunto A. 
 * 	Conjunto B. 
 * Retorno: 
 * 	Conjunto formado por los elementos de A que no están en B. 
 * 	i.e A - B. 
 */
conjunto Conjunto_Diferencia(conjunto, conjunto); 

// PROCEDIMIENTOS


/* Imprime los elementos del conjunto. 
 * Lista de números enteros que se encuentran en el conjunto.  
 * Parámetros: 
 * 	Conjunto c.
 */
void Conjunto_Imprimir(conjunto); 

/*
 * Obtiene un elemento arbitrario de un conjunto no vacío
 * Parámetros: 
 * 	Conjunto no vacío del cuál sacar el elemento.
 */
int Conjunto_ObtenerElemento(conjunto);


