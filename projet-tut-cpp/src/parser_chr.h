/*

UTILISATION DU PARSEUR-CHRONIQUE

- Le fichier des chroniques doit s'appeler "chroniques.txt et se trouver à l'adresse "./txt/".
- La syntaxe pour chaque chronique est exactement : nom;nb_contraintes:(nom1,temps1,type1)(nom2,temps2,type2)...(nomi,tempsi,typei)
- Chaque chronique est séparée par un retour à la ligne
- Un temps égal à 1000000 est considéré comme un temps infini
- Un temps égal à -1 correspond à l'absence d'une contrainte de temps (il ne doit être utilisé qu'uniquement pour les chroniques de type 1 ou 4)

*/

#ifndef PARSER_CHR_H_INCLUDED
#define PARSER_CHR_H_INCLUDED

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "chronique.h"
#include "contrainte.h"
#include "event.h"
using namespace std;

/* FUNCTIONS */

std::list<chronique> parser_chroniques(); // Parseur : traduit chroniques.txt en chroniques
void afficheur_liste_chr(std::list<chronique> l_chr); // Affiche la liste des chroniques comme elle
                                                      // apparait dans le fichier chroniques.txt

#endif
