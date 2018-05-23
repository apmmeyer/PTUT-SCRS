/*

UTILISATION DU PARSEUR-CHRONIQUE

- Le fichier des chroniques doit s'appeler "chroniques.txt et se trouver à l'adresse "./txt/".
- La syntaxe pour chaque chronique est exactement : nom;nb_contraintes;()()...()
- Chaque chronique est séparée par un retour à la ligne

*/

#ifndef PARSER_CHR_H_INCLUDED
#define PARSER_CHR_H_INCLUDED

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "chronique.h"
using namespace std;

/* FUNCTIONS */

std::list<chronique> parser_chroniques(); // Parseur : traduit chroniques.txt en chroniques

#endif
