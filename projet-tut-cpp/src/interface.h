#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "chronique.h"
#include "event.h"
#include "contrainte.h"
#include "parser.h"
#include "parser_chr.h"
#include "parser_evt.h"
using namespace std;

/* VARIABLES GLOBALES APPELEES */

extern std::list<chronique> MES_CHRONIQUES ;

/* FUNCTIONS */

// Fixe la taille d'affichage
void set_size();

// Gestion de l'affichage
void graph_completion(chronique chron);

// Lancement de l'interface
void interface();

#endif // INTERFACE_H_INCLUDED
