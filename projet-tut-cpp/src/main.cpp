/*

--SYSTEME DE RECONNAISSANCE DE CHRONIQUES--

Code developpe pour le projet tuteuré "SURVEILLANCE DES PERSONNES DANS L'HABITAT INTELLIGENT" (2018)
par Valentine Bellet, Benjamin Blum, Amélie Meyer, Ninni Stenkula et Amaury Vignolles

Compilation : g++.exe -Wall -fexceptions -g -std=c++14  -c C:\Users\acer\Desktop\projet-tut-cpp\main.cpp -o obj\Debug\main.o
IDE : Code::Blocks 16.01

Fonctionnement : le fichier .exe doit être à la racine de /src et /txt.

*/

#include <iostream>
#include <string>
#include "chronique.h"
#include "event.h"
#include "contrainte.h"
#include "parser.h"
#include "parser_chr.h"
#include "parser_event.h"
#include <vector>
using namespace std;


/* VARIABLES GLOBALES */

int HEURE_COURANTE = 0;
std::list<event> MES_EVENTS ;
std::list<chronique> MES_CHRONIQUES ;
std::vector<elmt_sequence> MA_SEQUENCE ;

/* MAIN */

int main(){

    // recuperation des évenements
	MES_EVENTS = parser_evenements();

    // recuperation des chroniques
	MES_CHRONIQUES = parser_chroniques();

    // recuperation de la sequence
	MA_SEQUENCE = parser();


	// algorithme de lecture de la sequence
	for(vector<elmt_sequence>::iterator vec= MA_SEQUENCE.begin(); vec!=MA_SEQUENCE.end();vec++) {

		// mise a jour de l'heure courante
		HEURE_COURANTE = (*vec).get_date();

		// mise a jour de la liste d'event
        for(list<event>::iterator eve=  MES_EVENTS.begin(); eve!=MES_EVENTS.end(); eve++) {

            // mise a jour de l'evenement dans la liste des events quand on a trouvé le bon event
            // dans la liste des events (recherche par nom)
            if ( ((*eve).get_label()) == (*vec).get_label() ) {

                (*eve).set_occured(true);
                (*eve).set_h_event((*vec).get_date());
                (*eve).set_occurence((*eve).get_nb_occurence()+1);

                // mise a jour de la liste des chroniques
                for(list<chronique>::iterator chr= MES_CHRONIQUES.begin(); chr!=MES_CHRONIQUES.end(); chr++){

                    /** COMPLETER **/

                }

            }

        }

	}


	/***************** PROCEDURES DE TEST ******************/

    /*
    // TEST DE FONCTIONNEMENT  : AFFICHAGE DE LA SEQUENCE LUE

    vector<elmt_sequence>::iterator it;
	for(it=MA_SEQUENCE.begin(); it!=MA_SEQUENCE.end(); it++) {
		(*it).afficher();
	}
    */


    /*
    // TEST DE FONCTIONNEMENT  : AFFICHAGE DES EVENEMENTS LUS

    list<event>::iterator it;
	for(it=MES_EVENTS.begin(); it!=MES_EVENTS.end(); it++) {
		(*it).afficher();
	}
    */


    // TEST DE FONCTIONNEMENT  : AFFICHAGE DES CHRONIQUES LUES

    list<chronique>::iterator it;
	for(it=MES_CHRONIQUES.begin(); it!=MES_CHRONIQUES.end(); it++) {
		(*it).afficher();
	}
    cout<<endl;
    MES_CHRONIQUES.front().get_contraintes().front().afficher_contrainte();


	return 0;
}
