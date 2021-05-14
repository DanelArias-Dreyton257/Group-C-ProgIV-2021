#include "Miembro.h"
#include "Familia.h"
#include "ConHijos.h"
#include "ArbolFamilias.h"

#include <iostream>
using namespace std;

int main() {
	Miembro luis("Luis Diez", 60 /*años*/);
	Miembro marta("Marta Sanchez", 58);
	Miembro angel("Angel Diez", 32);
	Miembro laura("Laura Ponte", 30);
	Miembro hodei("Hodei Diez", 2);
	Miembro ana("Ana Diez", 7);
	Miembro pablo("Pablo Diez", 10);
	Miembro jon("Jon Pena", 40);
	Miembro maite("Maite Pazos", 35);

	cout << luis.toStr() << " os desea suerte en el examen." << endl;

	//PARTE 1--------------------------------
	Familia f1(&jon, &maite);

	//PARTE 2--------------------------------
	cout<<endl<<endl<<"PARTE 2 ----------------------------------------------"<<endl<<endl;
	ConHijos f2(&luis, &marta);
	f2.addHijo(&angel);

	ConHijos f3(&angel, &laura);
	f3.addHijo(&hodei);
	f3.addHijo(&ana);
	f3.addHijo(&pablo);

	f1.imprimir();
	f3.imprimir();

	//PARTE 4--------------------------------
	cout<<endl<<endl<<"PARTE 4 ----------------------------------------------"<<endl<<endl;

	ArbolFamilias a;
	a.anadirFamilia(&f1);
	a.anadirFamilia(&f2);
	a.anadirFamilia(&f3);

	int edad = 35;
	cout << "Menores "<<edad<<" años: "<<a.contarMenoresEdad(edad)<<" miembros"<<endl;

	cout<<endl;

	char inicial = 'L';
	cout <<"Conyuges cuyo nombre empieza por "<<inicial<<": "<<endl;

	int numMiembros = 0;
	Miembro **listaInicial = a.getConyugesInicial(&numMiembros, inicial);

	for (int i = 0; i< numMiembros ; i++){
		cout<< listaInicial[i]->toStr()<<endl;
	}

	return 0;
}
