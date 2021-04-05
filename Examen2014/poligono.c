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
#include <stdlib.h>
/**
 * Imprime el poligono mostrndo los diferentes puntos de este
 * @param Poligono a imprimir
 */
void imprimirPoligono(Poligono poli) {
	printf("El poligono tiene los siguientes puntos:\n");
	for (int i = 0; i < poli.numVertices; i++) {
		printf("\t%i. ", i + 1);
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
	//Cerrar la figura, uniendo el ultimo con el primero
	per += distancia(poli.vertices[poli.numVertices - 1], poli.vertices[0]);
	return per;
}
/**
 * Libera la memoria dinamica reservada por el poligono y sus puntos
 * @param poli puntero al poligono a liberar
 */
void liberar(Poligono *poli) {
	//Libera los vetices
	for (int i = 0; i < poli->numVertices; i++) {
		free((poli->vertices) + i);
	}
	//Libera el poligono en si
	free(poli);
}
/**
 * Anyade un punto al poligono. Si el poligono no tenia puntos, reserva memoria para que pueda almacenar el punto a
 * introducir y en caso de que ya, almacenara puntos hace realloc para tener sitio para el punto nuevo.
 * @param poli puntero al poligono donde se quiere introducir el vertice
 * @param p punto que representa el vertice a anyadir
 */
void anadirVertice(Poligono *poli, Punto p) {
	poli->numVertices++; //aumenta el numero de vertices
	if (poli->numVertices > 1) {
		//Realloc para que haya espacio
		Punto *verticesRealloc = realloc(poli->vertices,
				sizeof(Punto) * poli->numVertices);
		poli->vertices = verticesRealloc;
		//Guarda el punto
		poli->vertices[poli->numVertices - 1] = p;
	} else {
		//malloc para que haya espacio
		poli->vertices = malloc(sizeof(Punto));
		poli->numVertices = 1;

		poli->vertices[0] = p;
	}

}
/**
 * Copia la informacion del poli2 en el poli1
 * Para esto es necesario que poli1, haya reservado la memoria previamente.
 * No es neceserio reservar la memoria para los puntos pues esta funcion ya lo hace automaticamente
 * @param poli1 puntero al poligono destino de la copia
 * @param poli2 puntero al poligono que se quiere copiar
 */
void copiarPoligono(Poligono *poli1, Poligono *poli2) {
	poli1->numVertices = poli2->numVertices;

	poli1->vertices = malloc(sizeof(Punto) * poli2->numVertices);
	for (int i = 0; i < poli2->numVertices; i++) {
		poli1->vertices[i] = poli2->vertices[i];
	}
}
