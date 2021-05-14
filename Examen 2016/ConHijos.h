/*
 * ConHijos.h
 *
 *  Created on: 14 may. 2021
 *      Author: danel
 */

#ifndef CONHIJOS_H_
#define CONHIJOS_H_

#include "Familia.h"

class ConHijos: public Familia {
private:
	int numHijos = 0;
	Miembro **hijos;
public:
	ConHijos(Miembro* conyugeH, Miembro* conyugeM, int numHijos);
	ConHijos(Miembro* conyugeH, Miembro* conyugeM);
	virtual ~ConHijos();
	ConHijos(const ConHijos &other);
	int getNumHijos() const;
	Miembro* getHijo(int pos);
	void addHijo(Miembro *hijo);
	void imprimir();
	int contarMenoresEdad(int edad);
};

#endif /* CONHIJOS_H_ */
