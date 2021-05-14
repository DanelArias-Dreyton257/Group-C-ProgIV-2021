/*
 * ArbolFamilias.h
 *
 *  Created on: 14 may. 2021
 *      Author: danel y jon ander
 */

#ifndef ARBOLFAMILIAS_H_
#define ARBOLFAMILIAS_H_

#include "Familia.h"
#include "Miembro.h"

class ArbolFamilias {
private:
	static const int NUM_MAX = 5;
	int numFamilias = 0;
	Familia** familias = new Familia*[5];
public:
	ArbolFamilias();
	virtual ~ArbolFamilias();
	void anadirFamilia(Familia* f);
	void imprimir();
	int contarMenoresEdad(int edad);
	Miembro** getConyugesInicial(int *numMiembros, char inicial);
};

#endif /* ARBOLFAMILIAS_H_ */
