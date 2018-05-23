#ifndef CONTRAINTE_H_INCLUDED
#define CONTRAINTE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "event.h"
using namespace std;

/* DEFINITION DE CONSTANTES */

// types de contraintes
#define _UNKNOWN          0    // Type inconnu
#define _SIMPLE_EVENT     1    // A pour t(A) quelconque
#define _SUCCESSION       2    // A puis B et t(B)-t(A)
#define _SUCCESSION_TIMED 3    // A puis B et t(B)-t(A) < T
#define _NO_EVENT         4    // Pas d'évènement A depuis le dernier élément
#define _CHRONIQUE_EVENT  5    // A déclenché par une chronique

/* CLASSES */

class contrainte {

private:

  /* ATTRIBUTS */

  string label; // nom de la contrainte
  event evenement; // evenement attendu ou refusé (selon le type de contrainte), attention event particulier si chronique !
  int type; //type de contrainte

public:

  /* CONSTRUCTEURS */

  // Constructeur simple
  contrainte(){
    label="";
    type=0;
  }

  // Constructeur évolué, créé la contrainte à partir des données
  contrainte(string nom, int type_contrainte, event evt){
    label=nom;
    evenement=evt;
    type=type_contrainte;
  }

  /* ASSESSEURS */

  // Assesseur, ressort le nom de la contrainte
  string get_label(){
	return label;
  }

  // Assesseur, ressort le type de la contrainte
  int get_type(){
	return type;
  }

  // Assesseur, ressort l'event associé la contrainte
  event get_event(){
	return evenement;
  }

  // Mutateur, change le nom de la contrainte
  void set_label(string name){
    label = name;
  }

  // Mutateur, change le nom de la contrainte
  void set_type(int type_contrainte){
    type = type_contrainte;
  }

  // Mutateur, change l'event associé à la contrainte
  void set_type(event evt){
    evenement = evt;
  }
  /* METHODES */

  // Affiche les datas de la contrainte dans le terminal
  void afficher_contrainte(){
    cout<<"contrainte : "<<label<<" type : "<<type<<" evenement associe ";
    evenement.afficher();
    cout<<endl;
  }

};


/* FUNCTIONS */


#endif // CONTRAINTE_H_INCLUDED
