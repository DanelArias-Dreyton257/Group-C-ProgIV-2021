/*
 * main.c
 *
 *  Created on: 4 abr. 2021
 *      Author: danel y jonander
 */
#include "punto.h"
#include <stdio.h>

int main(int argc, char **argv) {
	Punto p1;
	Punto p2;
	char *pasos[] = { "introduzca la X del primer punto:\n",
			"introduzca la Y del primer punto:\n",
			"introduzca la X del segundo punto:\n",
			"introduzca la Y del segundo punto:\n" };
	for (int i = 0; i < 4; i++) {

		printf("\n%i.%s", i + 1, pasos[i]);
		fflush(stdout);
		fflush(stdin);
		int j;
		scanf("%i", &j);
		if (i == 0) {
			p1.x = j;
		} else if (i == 1) {
			p1.y = j;
		} else if (i == 2) {
			p2.x = j;
		} else if (i == 3) {
			p2.y = j;
		}
	}

	imprimirPunto(p1);
	imprimirPunto(p2);

	printf("Distancia: %f\n", distancia(p1, p2));

	trasladarXY(&p1, &p2, 5, 6);

	printf("Despues de trasladar...\n");
	printf("Distancia: %f\n", distancia(p1, p2));
	imprimirPunto(p1);
	imprimirPunto(p2);

	return 0;
}
