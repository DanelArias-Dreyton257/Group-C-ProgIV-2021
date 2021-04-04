/*
 * punto.h
 *
 *  Created on: 4 abr. 2021
 *      Author: danel y jonander
 */

#ifndef PUNTO_H_
#define PUNTO_H_
typedef struct {
	int x;
	int y;
} Punto;

void imprimirPunto(Punto p);
float distancia(Punto p1, Punto p2);
void trasladarXY(Punto p1, Punto p2, int x, int y);

#endif /* PUNTO_H_ */
