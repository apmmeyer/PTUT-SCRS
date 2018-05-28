/*

UTILISATION DU PARSEUR

- Le fichier des séquences doit s'appeler "sequence.txt et se trouver à l'adresse "./txt/".
- La syntaxe pour chaque couple label-date est exactement : (label;date)
- Chaque couple est séparé par un retour à la ligne

*/

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "sequence.h"
using namespace std;

/* FUNCTIONS */

std::vector<elmt_sequence> parser(); // Parseur : traduit sequence.txt en sequence interpretable
void afficheur_sequence(std::vector<elmt_sequence> seq); // Affiche la séquence comme elle apparait dans le fichier sequence.txt

#endif
