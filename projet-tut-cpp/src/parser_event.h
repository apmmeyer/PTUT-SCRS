/*

UTILISATION DU PARSEUR-EVENEMENTS

- Le fichier des evenements doit s'appeler "events.txt et se trouver à l'adresse "./txt/".
- La syntaxe pour chaque evenement est exactement : nom
- Chaque evenement est séparé par un retour à la ligne

*/

#ifndef PARSER_EVENT_H_INCLUDED
#define PARSER_EVENT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "event.h"
using namespace std;

/* FUNCTIONS */

std::list<event> parser_evenements(); // Parseur : traduit events.txt en evenements
void afficheur_liste_evt(std::list<event> l_evt); // Affiche la liste des evenements comme elle
                                                  // apparait dans le fichier events.txt

#endif
