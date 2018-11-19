
/* Imprime un número decimal entero dentro del rango 0 - (2⁶⁴ - 1) en número binario. 
 * Parámetros: 
 * 	Número decimal a imprimir. 
 * Retorno: 
 * 	Ninguno. 
 */
void Muestra_en_bits(unsigned long int); 


int main(void)
{
	conjunto c = 0;
	c = Conjunto_Agregar(c, 3);
	c = Conjunto_Agregar(c, 4);
	c = Conjunto_Eliminar(c, 4);
	Muestra_en_bits(c);
	return 0; 
}

void Muestra_en_bits (unsigned long int u)
{
	int i;
	unsigned long int  u1 = 1; 
	u1 = u1 << 63;

	for(i = 1; i <= 64; i++)
	{
		if(u & u1)
			putchar('1');
		else 
			putchar('0');

		u = u << 1; 

		if(i % 8 == 0) printf(" ");
	}
	printf("\n"); 
}

