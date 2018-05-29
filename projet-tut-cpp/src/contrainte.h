#ifndef CONTRAINTE_H_INCLUDED
#define CONTRAINTE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include "event.h"
using namespace std;

/* DEFINITION DE CONSTANTES */

// types de contraintes
#define _UNKNOWN          0    // Type inconnu
#define _SIMPLE_EVENT     1    // A pour t(A) quelconque
#define _EVENT_TIMED      2    // A arrive avant T après le dernier event
#define _NO_EVENT         3    // Pas d'évènement A depuis le dernier élément pendant un temps T
#define _CHRONIQUE_EVENT  4    // A déclenché par une chronique
#define _NO_EVENT_INFINI  5    // A n'apparait jamais

/* VARIABLES GLOBALES APPELEES */

extern std::list<event> MES_EVENTS ;

/* CLASSES */

class contrainte {

private:

  /* ATTRIBUTS */

  event evenement; // evenement attendu ou refusé (selon le type de contrainte),
                   // attention event particulier si chronique !
  int temps; // contrainte de temps, 0 si pas de contrainte
  int type; //type de contrainte

public:

  /* CONSTRUCTEURS */

  // Constructeur simple
  contrainte();

  // Constructeur évolué, créé la contrainte à partir des données
  contrainte(int time, int type_contrainte, string nom_evt);

  /* OPERATEURS */

  contrainte operator =(const contrainte &c);

  /* ASSESSEURS */

  // Assesseur, ressort le type de la contrainte
  int get_type();

  // Assesseur, ressort l'event associé la contrainte
  event get_event();

  // Assesseur, ressort le temps associé la contrainte
  int get_time();

  // Mutateur, change le nom de la contrainte
  void set_type(int type_contrainte);

  // Mutateur, change l'event associé à la contrainte
  void set_type(event evt);

  /* METHODES */

  // Affiche les datas de la contrainte dans le terminal
  void afficher_contrainte();

};


/* FUNCTIONS */


#endif // CONTRAINTE_H_INCLUDED
