/*
 * Input.h
 *
 *  Created on: Oct 15, 2021
 *      Author: hernan.j.corrado
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int PedirEntero (char mensaje[]);
int PedirString (char cadena[], char mensaje[], int tam);
float IngresarFlotante(char mensaje[]);
#endif /* INPUT_H_ */
