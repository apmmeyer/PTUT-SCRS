#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/* CLASSES */

// Event unitaire
class event {

private:

  /* ATTRIBUTS */

  string label; //initialisé par le fichier de définition des events
  bool occured; // initialisé à false, indique si l’événement est arrivé au moins une fois
  int nb_occurence; // initialisé à 0, indique le nombre d’apparition de l’événement dans la séquence
  std::vector<int> date; // tableau des heures d'apparition de l'évènement

public:

 /* CONSTRUCTEURS */

  // Constructeur simple
  event();

  // Constructeur évolué, créé l'event à partir des données
  event(string nom);

  /* OPERATEURS */

  event operator =(const event &e);

  /* ASSESSEURS */

  // Assesseur, ressort le nom de l'event
  string get_label();

  // Assesseur, ressort l'état de l'event (occured ou non)
  bool get_occured();

  // Assesseur, ressort le nombre d'occurence
  int get_nb_occurence();

  // Assesseur, ressort le tableau des heures d'occurence
  std::vector<int> get_h_occur();

  // Assesseur, ressort l'heure de la dernière occurence
  int get_last_h_occur();

  // Mutateur, change le label de l'élément
  void set_label(string name);

  // Mutateur, change la valeur du nombre de validation de la chronique
  void set_occurence(int nb);

  // Mutateur, change la valeur du booleen occured
  void set_occured(bool occur);

  // Mutateur, ajoute une valeur dans les heures d'apparition de l'event
  void set_h_event(int heure);

    // Reinitialisateur, remet à 0 le tableau des heures de validation
  void reset_h_event();

  // Reinitialisateur, réinitialise tous les attributs
  void reinit_event_all();

  /* METHODES */

  // Affiche certains éléments dans la console
  void afficher();

  // Affiche les heures d'occurence de l'event dans le terminal
  void afficher_heures_occur();

  // Affiche le nombre de fois où l'event est arrivé
  void afficher_nb_occurence();


};

/* FUNCTIONS */


#endif // EVENT_H_INCLUDED
