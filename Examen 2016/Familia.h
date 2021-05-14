/*
 * Familia.h
 *
 *  Created on: 14 may. 2021
 *      Author: danel
 */

#ifndef FAMILIA_H_
#define FAMILIA_H_

#include "Miembro.h"

class Familia {
protected:
	Miembro *conyugeH;
	Miembro *conyugeM;
public:
	Familia(Miembro *conyugeH, Miembro *conyugeM);
	Familia(const Familia &other);
	virtual ~Familia();
	Miembro* getConyugeH() const;
	Miembro* getConyugeM() const;
	char* getNombre();
	virtual void imprimir();
	virtual int contarMenoresEdad(int edad);

};

#endif /* FAMILIA_H_ */
