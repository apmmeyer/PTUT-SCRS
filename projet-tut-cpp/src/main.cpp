/*

--SYSTEME DE RECONNAISSANCE DE CHRONIQUES--

Code developpe pour le projet tuteuré "SURVEILLANCE DES PERSONNES DANS L'HABITAT INTELLIGENT" (2018)
par Valentine Bellet, Benjamin Blum, Amélie Meyer, Ninni Stenkula et Amaury Vignolles

Compilation : g++.exe -Wall -fexceptions -g -std=c++14  -c C:\Users\acer\Desktop\projet-tut-cpp\main.cpp -o obj\Debug\main.o
IDE : Code::Blocks 16.01

*/

#include <iostream>
#include <string>
#include "chronique.h"
#include "event.h"
#include "contrainte.h"
#include "parser.h"
#include <vector>
using namespace std;


/* VARIABLES GLOBALES */

int HEURE_COURANTE = 0;

/* MAIN */

int main(){

    // recuperation de la sequence
	std::vector<elmt_sequence> sequence = parser();


    /* TEST DE FONCTIONNEMENT  : AFFICHAGE DE LA SEQUENCE LUE

    vector<elmt_sequence>::iterator it;
	for(it=sequence.begin(); it!=sequence.end(); it++) {
		(*it).afficher();
	}
	*/

	return 0;
}
