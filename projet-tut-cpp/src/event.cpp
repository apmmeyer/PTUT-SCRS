#include "event.h"

 /* CONSTRUCTEURS */

  // Constructeur simple
  event::event(){
    label="";
    occured=false;
    nb_occurence=0;
    date.clear();
  }

  // Constructeur évolué, créé l'event à partir des données
  event::event(string nom){
    label=nom;
    occured=false;
    nb_occurence=0;
    date.clear();
  }

  /* OPERATEURS */

  event event::operator =(const event &e){
    label=e.label;
    occured=e.occured;
    nb_occurence=e.nb_occurence;
    date=date;
    return *this;
  }

  /* ASSESSEURS */

  // Assesseur, ressort le nom de l'event
  string event::get_label(){
	return label;
  }

  // Assesseur, ressort l'état de l'event (occured ou non)
  bool event::get_occured(){
	return occured;
  }

  // Assesseur, ressort le nombre d'occurence
  int event::get_nb_occurence(){
	return nb_occurence;
  }

  // Assesseur, ressort le tableau des heures d'occurence
  std::vector<int> event::get_h_occur(){
	return date;
  }

  // Assesseur, ressort l'heure de la dernière occurence
  int event::get_last_h_occur(){
	return (*date.end());
  }

  // Mutateur, change le label de l'élément
  void event::set_label(string name){
    label = name;
  }

  // Mutateur, change la valeur du nombre de validation de la chronique
  void event::set_occurence(int nb){
    nb_occurence = nb;
  }

  // Mutateur, change la valeur du booleen occured
  void event::set_occured(bool occur){
    occured = occur;
  }

  // Mutateur, ajoute une valeur dans les heures d'apparition de l'event
  void event::set_h_event(int heure){
    date.push_back(heure);
  }

    // Reinitialisateur, remet à 0 le tableau des heures de validation
  void event::reset_h_event(){
    date.clear();
  }

  // Reinitialisateur, réinitialise tous les attributs
  void event::reinit_event_all(){
    label="";
    occured=false;
    nb_occurence=0;
    date.clear();
  }

  /* METHODES */

  // Affiche certains éléments dans la console
  void event::afficher(){
    cout<<"nom = "<<label<<endl;
    cout<<"event occured = "<<occured<<endl;
    if (occured) {
        cout<<"nombre d'occurence = "<<nb_occurence<<endl;
        cout<<"derniere validation = "<<date.back()<<endl;
    }
  }

  // Affiche les heures d'occurence de l'event dans le terminal
  void event::afficher_heures_occur(){
    vector<int>::iterator it; // iterateur
    for (it = date.begin(); it != date.end() ; it++)
    {
        cout<<"occurence à "<<(*it)<<endl;
    }
  }

  // Affiche le nombre de fois où l'event est arrivé
  void event::afficher_nb_occurence(){
    cout<<"nombre d'occurence = "<<nb_occurence<<endl;
  }
