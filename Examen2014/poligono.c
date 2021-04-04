/*
 * poligono.c
 *
 *  Created on: 4 abr. 2021
 *      Author: danel y jonander
 *
 */
#include <stdio.h>
#include "punto.h"
#include "poligono.h"
/**
 * Imprime el poligono mostrndo los diferentes puntos de este
 * @param Poligono a imprimir
 */
void imprimirPoligono(Poligono poli) {
	printf("El poligono tiene los siguientes puntos:\n");
	for (int i = 0; i < poli.numVertices; i++) {
		printf("\t");
		imprimirPunto(poli.vertices[i]);
	}
}
/**
 * Calcula el perimetro del poligono considerando su orden el de la array de estos
 * @param Poligono a imprimir
 * @return perimetro calculado
 */
float perimetro(Poligono poli) {
	float per = 0;
	for (int i = 0; i < poli.numVertices - 1; i++) {
		per += distancia(poli.vertices[i], poli.vertices[i + 1]);
	}
	return per;
}

void liberar(Poligono poli) {
	//TODO
}

void anadirVertice(Poligono poli, Punto p) {
	//TODO
}

void copiarPoligono(Poligono poli1, Poligono poli2) {
	//TODO
}
