/*
 * main.c
 *
 *  Created on: 4 abr. 2021
 *      Author: danel y jonander
 */
#include "punto.h"
#include <stdio.h>
#include <stdlib.h>
#include "poligono.h"

Punto* puntoPorInput();

int main(int argc, char **argv) {

//	PARTE 1
//
	//Pedir los puntos por teclado
	Punto *p1 = puntoPorInput();
	Punto *p2 = puntoPorInput();

	imprimirPunto(*p1);
	imprimirPunto(*p2);

	printf("Distancia: %f\n", distancia(*p1, *p2));

	//Traslado
	trasladarXY(p1, p2, 5, 6);

	printf("Despues de trasladar...\n");
	printf("Distancia: %f\n", distancia(*p1, *p2));
	imprimirPunto(*p1);
	imprimirPunto(*p2);

	//liberar los puntos
	free(p1);
	free(p2);
//
//----------------------------------------------------------------------------------------
//
//	PARTE 2
//
	int numVertices2;

	//Pedir el numero de vertices por teclado
	printf("Introduce el numero de vertices del poligono:\n");
	fflush(stdin);
	fflush(stdout);
	scanf("%i", &numVertices2);

	//Ir pidiendo las coordenadas de los vertices por teclado
	Poligono *poli2 = malloc(sizeof(Poligono));
	poli2->numVertices = 0;
	printf("Introduce las coordenadas de los puntos:\n");
	//Va pidiendo e introduciendo esos puntos en el poligono
	for (int i = 0; i < numVertices2; i++) {
		printf("Vertice %i. ", i + 1);
		Punto *p = puntoPorInput();
		anadirVertice(poli2, *p);
	}

	imprimirPoligono(*poli2);

	printf("Perimetro: %f\n", perimetro(*poli2));

	//Libera el poligono
	liberar(poli2);
//
//---------------------------------------------------------------------------------------------
//
//	PARTE 3
//
	int numVertices3;

	//Pedir el numero de vertices por teclado
	printf("Introduce el numero de vertices del poligono:\n");
	fflush(stdin);
	fflush(stdout);
	scanf("%i", &numVertices3);

	//Crea un poligono "de prueba" con el numero de vertices indicado
	Poligono *poli3 = malloc(sizeof(Poligono));
	poli3->numVertices = 0;
	for (int i = 0; i < numVertices3; i++) {
		Punto p = { 2 * i + 1, 2 * (i + 1) }; //Va sacando puntos: (1,2), (3,4), (5,6)....(x,x+1)
		anadirVertice(poli3, p);
	}

	printf("Antes de anyadir el vertice:\n");
	imprimirPoligono(*poli3);

	//Anadir vertice
	printf("Ahora, vamos a anyadir un vertice al poligono:\n");

	Punto *p = puntoPorInput();
	anadirVertice(poli3, *p);

	printf("Despues de anyadir el vertice:\n");
	imprimirPoligono(*poli3);

	//Copiar poligono
	printf("Poligono copiado:\n");
	Poligono *poli4 = malloc(sizeof(Poligono));
	copiarPoligono(poli4, poli3);
	imprimirPoligono(*poli4);

	//libera los poligonos
	liberar(poli3);
	liberar(poli4);

	return 0;
}
/**
 * Pregunta las coordenadas del punto por consola y hace devuelve un puntero a
 * un punto habiendo reservado memoria dinamica para este
 * @return puntero al punto ocn las coordenadas introducidas
 */
Punto* puntoPorInput() {
	Punto *p = malloc(sizeof(Punto));
	int x, y;

	printf("Introduce la X del punto:\n");
	fflush(stdin);
	fflush(stdout);

	scanf("%i", &x);

	printf("Introduce la Y del punto:\n");
	fflush(stdin);
	fflush(stdout);

	scanf("%i", &y);

	p->x = x;
	p->y = y;

	return p;
}
