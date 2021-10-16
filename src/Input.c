/*
 * Input.c
 *
 *  Created on: Oct 15, 2021
 *      Author: hernan.j.corrado
 */

#include "Input.h"


int PedirEntero (char mensaje[]){

     int numeroIngresado;

	 printf("%s", mensaje);
	 fflush(stdin);
	 scanf("%d", &numeroIngresado);


return numeroIngresado;


	}


float IngresarFlotante(char mensaje[])
{
	float numeroIngresado;
	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);

	return numeroIngresado;
}


int PedirString (char cadena[], char mensaje[], int tam)
	{
		char stringingresado[500];
		int retorno = 0;

		//Tenemos que corroborar que los valores ingresados no sean Nulos, tanto el mensaje como la posicion a donde vamos a guardarlos
		if(mensaje != NULL && cadena != NULL)
		{
            retorno = 1;
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%[^\n]", stringingresado);
			//Si el cliente ingresa un string superior al tamaño maximo, debemos corregir eso y volver a indicarle que tiene que ingresar de nuevo el string
			while (strlen(stringingresado) > tam)
				{
					printf("Reingrese: ");
					fflush(stdin);
					scanf("%[^\n]", stringingresado);
				}

			//Luego copiamos y pegamos el stringingresado en el array cadena original, es decir con esto vamos cargando el array principal.
			strcpy(cadena, stringingresado);

		}

     return retorno;

	}
