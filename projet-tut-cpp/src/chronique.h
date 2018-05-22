#ifndef CHRONIQUE_H_INCLUDED
#define CHRONIQUE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include "contrainte.h"
using namespace std;


/* CLASSES */

// Chronique unitaire
class chronique {

private:

  /* ATTRIBUTS */

  string nom; //initialisé par le fichier de définition des chroniques
  bool event_verify; // initialisé à false, utile pour les chroniques de chroniques
  int nb_validation; // initialisé à 0, indique le nombre de validation de la chronique
  std::vector<int> heure_validation; // tableau des heures de validation
  int nb_contraintes_restantes; // initialisé à nb_contraintes_total
  int nb_contraintes_total; // initialisé par le fichier de définition des chroniques
  // TYPE contraintes; // tableau de contraintes, initialisé par le fichier de définition des chroniques


  /* ASSESSEURS  */

  // Mutateur, change la valeur d'évènement de la chronique
  void set_event(bool event){
    event_verify = event;
  }

  // Reinitialisateur, remet à 0 la valeur du nombre de validation
  void reset_valid(){
    event_verify = 0;
  }

  // Reinitialisateur, remet à 0 le tableau des heures de validation
  void reset_h_valid(){
    heure_validation.clear();
  }

  // Reinitialisateur, remet au maximum la valeur des contraintes restantes à valider
  void reset_nb_contraintes(){
    nb_contraintes_restantes=nb_contraintes_total;
  }

public:

  /* CONSTRUCTEURS */

  // Constructeur évolué, créé la chronique à partir des données
  chronique(string label, int nb_contraintes){
    nom=label;
    event_verify=false;
    nb_validation=0;
    heure_validation.clear();
    nb_contraintes_restantes = nb_contraintes;
    nb_contraintes_total = nb_contraintes;
  // TYPE contraintes;
  }

  /* ASSESSEURS */

  // Assesseur, ressort le nom de la chronique
  string get_nom(){
	return nom;
  }

  // Assesseur, ressort l'état de la chronique (pour les chroniques de chroniques)
  bool get_event(){
	return event_verify;
  }

  // Assesseur, ressort le nombre de validation
  int get_nb_valid(){
	return nb_validation;
  }

  // Assesseur, ressort le nombre de validation
  std::vector<int> get_h_valid(){
	return heure_validation;
  }

  // Mutateur, change le label de l'élément
  void set_nom(string name){
    nom = name;
  }

  /* METHODES */

  // Affiche certains éléments dans la console
  void afficher(){
    cout<<"nom = "<<nom<<endl;
    cout<<"nombre de validation = "<<nb_validation<<endl;
    cout<<"derniere validation = "<<heure_validation.back()<<endl;
    cout<<"evenement detectable = "<<event_verify<<endl;
    cout<<"nombre de contraintes total = "<<nb_contraintes_total<<endl;
    cout<<"nombre de contraintes restantes = "<<nb_contraintes_restantes<<endl;
  }


};

/* FUNCTIONS */



#endif
