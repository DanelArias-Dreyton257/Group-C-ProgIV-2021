/*
 * main.c
 *
 *  Created on: 4 abr. 2021
 *      Author: danel y jonander
 */
#include "punto.h"
#include <stdio.h>

int main(int argc, char **argv) {
	Punto p1 = { 1, 2 };
	Punto p2 = { 3, 4 };
	imprimirPunto(p1);
	imprimirPunto(p2);

	printf("Distancia: %f\n",distancia(p1,p2));

	trasladarXY(&p1,&p2,5,6);

	printf("Despues de trasladar...\n");
	printf("Distancia: %f\n",distancia(p1,p2));
	imprimirPunto(p1);
	imprimirPunto(p2);

	return 0;
}
