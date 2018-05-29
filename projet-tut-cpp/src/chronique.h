#ifndef CHRONIQUE_H_INCLUDED
#define CHRONIQUE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "contrainte.h"
#include "event.h"
using namespace std;

/* VARIABLES GLOBALES APPELEES */

extern int HEURE_COURANTE; // Variable du temps, mise à jour tout au long de la lecture de la séquence

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
  std::vector<contrainte> contraintes; // tableau de contraintes, initialisé par le fichier
                                       // de définition des chroniques


public:

  /* CONSTRUCTEURS */

  // Constructeur simple
  chronique();

  // Constructeur évolué, créé la chronique à partir des données
  chronique(string label, int nb_contraintes, vector<contrainte> vect_contraintes);

  /* ASSESSEURS */

  // Assesseur, ressort le nom de la chronique
  string get_nom();

  // Assesseur, ressort l'état de la chronique (pour les chroniques de chroniques)
  bool get_event();

  // Assesseur, ressort le nombre de validation
  int get_nb_valid();

  // Assesseur, ressort le nombre de contraintes restantes
  int get_contraintes_restantes();


   // Assesseur, ressort le nombre de contraintes totales
  int get_contraintes_total();


  // Assesseur, ressort le tableau des heures de validation
  std::vector<int> get_h_valid();

  // Assesseur, ressort l'heure de la dernière validation
  int get_last_h_valid();

  // Assesseur, ressort le tableau des contraintes
  std::vector<contrainte> get_contraintes();

  // Mutateur, change la valeur du nombre de contraintes restantes de la chronique
  void set_contraintes_restantes(int nb);

  // Mutateur, change le label de l'élément
  void set_nom(string name);

    // Mutateur, change la valeur d'évènement de la chronique
  void set_event(bool event);

  // Mutateur, change la valeur du nombre de validation de la chronique
  void set_valid(int nb);

  // Mutateur, ajoute une valeur dans les heures de validation de la chronique
  void set_h_valid(int heure);

  // Reinitialisateur, remet à 0 la valeur du nombre de validation
  void reset_valid();

  // Reinitialisateur, remet à 0 le tableau des heures de validation
  void reset_h_valid();

  // Reinitialisateur, remet au maximum la valeur des contraintes restantes à valider
  void reset_nb_contraintes();

  // Reinitialisateur, réinitialise tous les attributs
  void reinit_chronique_all();

  /* METHODES */

  // Affiche certains éléments dans la console
  void afficher();

  // Affiche les heures de validation de la chronique dans le terminal
  void afficher_heures_validation();

  // Affiche le nombre de fois où la chronique a été terminée
  void afficher_nb_validation();

  // Valide la chronique (affiche un message dans le terminal pour annoncer la
  // validation de la chronique, incrémente nb_validation, met à jour heure_validation et
  // passe nb_contraintes_restantes à nb_contraintes_total)
  void validation_chronique();

};


#endif
