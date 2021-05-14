/*
 * ArbolFamilias.cpp
 *
 *  Created on: 14 may. 2021
 *      Author: danel
 */

#include "ArbolFamilias.h"
#include <iostream>
using namespace std;

ArbolFamilias::ArbolFamilias() {
}

ArbolFamilias::~ArbolFamilias() {
	delete familias;
}
void ArbolFamilias::anadirFamilia(Familia *f) {
	familias[numFamilias] = f;
	numFamilias++;
}
void ArbolFamilias::imprimir() {
	for (int i = 0; i < numFamilias; i++) {
		cout << "Familia " << i + 1 << ":" << endl;
		familias[i]->imprimir();
	}
}
int ArbolFamilias::contarMenoresEdad(int edad) {
	int cont = 0;
	for (int i = 0; i < numFamilias; i++) {
		cont += familias[i]->contarMenoresEdad(edad);
	}
	return cont;
}

Miembro** ArbolFamilias::getConyugesInicial(int *numMiembros, char inicial) {
	//Contar cuantos
	*numMiembros = 0;
	for (int i = 0; i < numFamilias; i++) {
		if (*(familias[i]->getConyugeH()->getNombre()) == inicial) {
			(*numMiembros)++;
		}
		if (*(familias[i]->getConyugeM()->getNombre()) == inicial) {
			(*numMiembros)++;
		}
	}
	//Reservar y llenar el array
	Miembro **miembros = new Miembro*[*numMiembros];
	int pos = 0;
	for (int i = 0; i < numFamilias; i++) {
		if (*(familias[i]->getConyugeH()->getNombre()) == inicial) {
			miembros[pos] = familias[i]->getConyugeH();
			pos++;
		}
		if (*(familias[i]->getConyugeM()->getNombre()) == inicial) {
			miembros[pos] = familias[i]->getConyugeM();
			pos++;
		}
	}
	return miembros;
}

