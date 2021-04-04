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
#include <stdlib.h>;
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

void liberar(Poligono *poli) {
	//Libera los vetices
	for (int i = 0; i < poli->numVertices; i++) {
		free((poli->vertices) + i);
	}
	//Libera el poligono en si
	free(poli);
}

void anadirVertice(Poligono *poli, Punto p) {
	poli->numVertices++; //aumenta el numero de vertices

	//Realloc para que haya espacio
	Punto *verticesRealloc = realloc(poli->vertices,
			sizeof(Punto) * poli->numVertices);
	poli->vertices = verticesRealloc;

	//Guarda el punto
	poli->vertices[poli->numVertices - 1] = p;

}

void copiarPoligono(Poligono *poli1, Poligono *poli2) {
	poli1->numVertices = poli2->numVertices;

	poli1->vertices = malloc(sizeof(Punto) * poli2->numVertices);
	for (int i = 0; i < poli2->numVertices; i++) {
		poli1->vertices[i] = poli2->vertices[i];
	}
}
