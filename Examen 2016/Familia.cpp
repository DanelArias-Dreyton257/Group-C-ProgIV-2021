/*
 * Familia.cpp
 *
 *  Created on: 14 may. 2021
 *      Author: danel
 */

#include "Familia.h"
#include <string.h>
#include <iostream>
using namespace std;

Familia::Familia(Miembro *conyugeH, Miembro *conyugeM) {
	this->conyugeH = conyugeH;
	this->conyugeM = conyugeM;
}
Familia::Familia(const Familia &other) {
	this->conyugeH = other.conyugeH;
	this->conyugeM = other.conyugeM;
}

Miembro* Familia::getConyugeH() const {
	return conyugeH;
}

Miembro* Familia::getConyugeM() const {
	return conyugeM;
}

Familia::~Familia() {
	delete conyugeH;
	delete conyugeM;
}

char* Familia::getNombre() {
	char *ApH = strchr(conyugeH->getNombre(), ' ');
	char *ApM = strchr(conyugeM->getNombre(), ' ');
	char *strFinal = new char[strlen(ApH) + 3 + strlen(ApM) + 1];
	strcpy(strFinal, ApH);
	strcat(strFinal, " - ");
	strcat(strFinal, ApM);
	return strFinal;
}

void Familia::imprimir() {
	/* Formato:
	 *
	 * ---
	 FAMILIA: Pena - Pazos
	 Marido: Jon Pena (40 años)
	 Mujer: Maite Pazos (35 años)
	 ---
	 */
	cout << "---" << endl << "FAMILIA: " << getNombre() << endl << "Marido: "
			<< conyugeH->toStr() << endl << "Mujer: " << conyugeM->toStr()
			<< endl << "---" << endl;
}

int Familia::contarMenoresEdad(int edad) {
	int cont = 0;
	if (conyugeH->getEdad() < edad) {
		cont++;
	}
	if (conyugeM->getEdad() < edad) {
		cont++;
	}
	return cont;
}

