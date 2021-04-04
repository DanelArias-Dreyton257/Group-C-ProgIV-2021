/*
 * punto.c
 *
 *  Created on: 4 abr. 2021
 *      Author: danel y jonander
 */

#include "punto.h"
#include <stdio.h>
#include <math.h>

void imprimirPunto(Punto p)
{
	printf("(%i, %i)\n", p.x, p.y);
}

float distancia(Punto p1, Punto p2){
	float distancia;
	distancia=sqrt((p2.x-p1.x)^2+(p2.y-p1.y)^2);
	return distancia;
}

void trasladarXY(Punto p1, Punto p2, int x, int y){
	p1.x=p1.x+x;
	p1.y=p1.y+y;
	p2.x=p2.x+x;
	p2.y=p2.y+y;
	return;
}
