/*
 * ConHijos.cpp
 *
 *  Created on: 14 may. 2021
 *      Author: danel
 */

#include "ConHijos.h"
#include "Familia.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

ConHijos::ConHijos(Miembro *conyugeH, Miembro *conyugeM, int numHijos) :
		Familia(conyugeH, conyugeM) {
	this->numHijos = numHijos;
	this->hijos = new Miembro*[numHijos];
}
ConHijos::ConHijos(Miembro *conyugeH, Miembro *conyugeM) :
		Familia(conyugeH, conyugeM) {
	this->numHijos = 0;
	this->hijos = NULL;
}

ConHijos::~ConHijos() {
	delete hijos;
}

int ConHijos::getNumHijos() const {
	return numHijos;
}

ConHijos::ConHijos(const ConHijos &other) :
		Familia(other) {
	this->numHijos = other.numHijos;
	this->hijos = other.hijos;
}
Miembro* ConHijos::getHijo(int pos) {
	return hijos[pos];
}
void ConHijos::addHijo(Miembro *hijo) {
	Miembro **hijosCopy = new Miembro*[numHijos + 1];

	for (int i = 0; i < numHijos; i++) {
		hijosCopy[i] = hijos[i];
	}

	hijosCopy[numHijos] = hijo;

	delete hijos;

	hijos = hijosCopy;
	numHijos++;

}

void ConHijos::imprimir() {
	/*
	 * ---
	 FAMILIA: Diez - Ponte
	 Marido: Angel Diez (32 años)
	 Mujer: Laura Ponte (30 años)
	 HIJOS:
	 Hijo 1: Hodei Diez (2 años)
	 Hijo 2: Ana Diez (7 años)
	 Hijo 3: Pablo Diez (10 años)
	 ---
	 */
	cout << "---" << endl << "FAMILIA: " << getNombre() << endl << "Marido: "
			<< conyugeH->toStr() << endl << "Mujer: " << conyugeM->toStr()
			<< endl << "HIJOS:" << endl;
	for (int i = 0; i < numHijos; i++) {
		cout << "Hijo " << i + 1 << ": " << hijos[i]->toStr() << endl;
	}
	cout << "---" << endl;

}
int ConHijos::contarMenoresEdad(int edad) {
	int cont = 0;
	if (conyugeH->getEdad() < edad) {
		cont++;
	}
	if (conyugeM->getEdad() < edad) {
		cont++;
	}
	for (int i = 0; i < numHijos; i++) {
		if (hijos[i]->getEdad() < edad) {
			cont++;
		}
	}
	return cont;
}

