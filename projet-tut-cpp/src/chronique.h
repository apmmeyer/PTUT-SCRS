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

extern int HEURE_COURANTE; // Variable du temps, mise � jour tout au long de la lecture de la s�quence

/* CLASSES */

// Chronique unitaire
class chronique {

private:

  /* ATTRIBUTS */

  string nom; //initialis� par le fichier de d�finition des chroniques
  bool event_verify; // initialis� � false, utile pour les chroniques de chroniques
  int nb_validation; // initialis� � 0, indique le nombre de validation de la chronique
  std::vector<int> heure_validation; // tableau des heures de validation
  int nb_contraintes_restantes; // initialis� � nb_contraintes_total
  int nb_contraintes_total; // initialis� par le fichier de d�finition des chroniques
  std::vector<contrainte> contraintes; // tableau de contraintes, initialis� par le fichier
                                       // de d�finition des chroniques


public:

  /* CONSTRUCTEURS */

  // Constructeur simple
  chronique();

  // Constructeur �volu�, cr�� la chronique � partir des donn�es
  chronique(string label, int nb_contraintes, vector<contrainte> vect_contraintes);

  /* ASSESSEURS */

  // Assesseur, ressort le nom de la chronique
  string get_nom();

  // Assesseur, ressort l'�tat de la chronique (pour les chroniques de chroniques)
  bool get_event();

  // Assesseur, ressort le nombre de validation
  int get_nb_valid();

  // Assesseur, ressort le nombre de contraintes restantes
  int get_contraintes_restantes();


   // Assesseur, ressort le nombre de contraintes totales
  int get_contraintes_total();


  // Assesseur, ressort le tableau des heures de validation
  std::vector<int> get_h_valid();

  // Assesseur, ressort l'heure de la derni�re validation
  int get_last_h_valid();

  // Assesseur, ressort le tableau des contraintes
  std::vector<contrainte> get_contraintes();

  // Mutateur, change la valeur du nombre de contraintes restantes de la chronique
  void set_contraintes_restantes(int nb);

  // Mutateur, change le label de l'�l�ment
  void set_nom(string name);

    // Mutateur, change la valeur d'�v�nement de la chronique
  void set_event(bool event);

  // Mutateur, change la valeur du nombre de validation de la chronique
  void set_valid(int nb);

  // Mutateur, ajoute une valeur dans les heures de validation de la chronique
  void set_h_valid(int heure);

  // Reinitialisateur, remet � 0 la valeur du nombre de validation
  void reset_valid();

  // Reinitialisateur, remet � 0 le tableau des heures de validation
  void reset_h_valid();

  // Reinitialisateur, remet au maximum la valeur des contraintes restantes � valider
  void reset_nb_contraintes();

  // Reinitialisateur, r�initialise tous les attributs
  void reinit_chronique_all();

  /* METHODES */

  // Affiche certains �l�ments dans la console
  void afficher();

  // Affiche les heures de validation de la chronique dans le terminal
  void afficher_heures_validation();

  // Affiche le nombre de fois o� la chronique a �t� termin�e
  void afficher_nb_validation();

  // Valide la chronique (affiche un message dans le terminal pour annoncer la
  // validation de la chronique, incr�mente nb_validation, met � jour heure_validation et
  // passe nb_contraintes_restantes � nb_contraintes_total)
  void validation_chronique();

};


#endif
