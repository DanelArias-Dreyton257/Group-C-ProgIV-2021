/*
 * punto.c
 *
 *  Created on: 4 abr. 2021
 *      Author: danel y jonander
 */

#include "punto.h"
#include <stdio.h>
#include <math.h>
/**
 * Imprime la informacion del punto
 * @param p punto a imprmir
 */
void imprimirPunto(Punto p) {
	printf("(%i, %i)\n", p.x, p.y);
}
/**
 * Devuelve un float con la distancia calculada entre los 2 puntos recibidos
 * @param p1 punto 1
 * @param p2 punto 2
 * @return distancia entre p1 y p2
 */
float distancia(Punto p1, Punto p2) {
	float distancia;
	distancia = sqrt(
			(p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
	return distancia;
}
/**
 * Hace una traslacion de coordenadas a 2 puntos. Hace la misma transformacion, indicada por los parametros x e y a ambos puntos.
 * La traslacion se hace incrementando las coordenadas x de ambos puntos por el  parametro x y igualmente con el parametro y
 * @param p1 puntero al punto1
 * @param p2 puntero al punto2
 * @param x traslacion en el eje X
 * @param y traslacion en el eje Y
 */
void trasladarXY(Punto *p1, Punto *p2, int x, int y) {

	p1->x += x;
	p2->x += x;
	p1->y += y;
	p2->y += y;

}
