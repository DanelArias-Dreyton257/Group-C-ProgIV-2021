/*
 * poligono.h
 *
 *  Created on: 4 abr. 2021
 *      Author: danel y jonander
 */

#ifndef POLIGONO_H_
#define POLIGONO_H_

#include "punto.h"

typedef struct {
	int numVertices;
	Punto *vertices;
} Poligono;

void imprimirPoligono(Poligono poli);
float perimetro(Poligono poli);
void liberar(Poligono poli);
void anadirVertice(Poligono poli, Punto p);
void copiarPoligono(Poligono poli1, Poligono poli2);

#endif /* POLIGONO_H_ */
