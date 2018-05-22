#ifndef CONTRAINTE_H_INCLUDED
#define CONTRAINTE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/* CLASSES */

///////////////////////////////// contrainte unitaire (classe mère)
class contrainte {

private:

  /* ATTRIBUTS */

  string label; // nom de la contrainte

public:

  /* CONSTRUCTEURS */

  contrainte(string nom){
    label=nom;
  }

  /* ASSESSEURS */

  // Assesseur, ressort le nom de la contrainte
  string get_label(){
	return label;
  }

  // Mutateur, change le nom de la contrainte
  void set_label(string name){
    label = name;
  }

  /* METHODES */

  // Affiche le nom de la contrainte dans le terminal
  void afficher_label(){
    cout<<"contrainte reconnue = "<<label<<endl;
  }

};


/////////////////////////////////// sous-contrainte c_event (classe fille)
class c_event : public contrainte {

private:

  /* ATTRIBUTS */

  string evenement_attendu; // label de l'event attendu, initialisé par le fichier de définition des chroniques

public:

  /* CONSTRUCTEURS */

  c_event(string nom_contrainte, string nom_event):contrainte(nom_contrainte){
    evenement_attendu=nom_event;
  }

  /* ASSESSEURS */

  // Assesseur, ressort le nom de l'evenement attendu
  string get_evenement_attendu(){
	return evenement_attendu;
  }

  // Mutateur, change le label de l'evenement attendu
  void set_evenement_attendu(string nom_event){
    evenement_attendu = nom_event;
  }

  /* METHODES */

  // Affiche l'evenement attendu dans le terminal
  void afficher_evenement_attendu(){
    cout<<"evenement attendu = "<<evenement_attendu<<endl;
  }

};


////////////////////////////// sous-contrainte c_timed_event (classe fille)
class c_timed_event : public contrainte {

private:

  /* ATTRIBUTS */

  string evenement_attendu; // label de l'event attendu, initialisé par le fichier de définition des chroniques
  int heure_limite; // date limite d’apparition de l’événement, initialisé par le fichier de définition des chroniques

public:

  /* CONSTRUCTEURS */

  c_timed_event(string nom_contrainte, string nom_event, int temps):contrainte(nom_contrainte){
    evenement_attendu=nom_event;
    heure_limite=temps;
  }

  /* ASSESSEURS */

  // Assesseur, ressort le nom de l'evenement attendu
  string get_evenement_attendu(){
	return evenement_attendu;
  }

  // Assesseur, ressort l'heure limite de l'evenement attendu
  int get_heure_limite(){
	return heure_limite;
  }

  // Mutateur, change le label de l'evenement attendu
  void set_evenement_attendu(string nom_event){
    evenement_attendu = nom_event;
  }

  // Mutateur, change l'heure limite de l'event attendu
  void set_h_lim(int temps){
    heure_limite = temps;
  }

  /* METHODES */

  // Affiche l'evenement attendu et son heure limite dans le terminal
  void afficher_evenement_attendu(){
    cout<<"evenement attendu = "<<evenement_attendu<<" avant "<<heure_limite<<endl;
  }

};


////////////////////////////// sous-contrainte c_no_event (classe fille)
class c_no_event : public contrainte {

private:

  /* ATTRIBUTS */

  string evenement_refuse ; // label de l'event non souhaité, initialisé par le fichier de définition des chroniques
  int heure_limite; // date limite d’apparition de l’événement, initialisé par le fichier de définition des chroniques

public:

  /* CONSTRUCTEURS */

  c_no_event(string nom_contrainte, string nom_event, int temps):contrainte(nom_contrainte){
    evenement_refuse=nom_event;
    heure_limite=temps;
  }

  /* ASSESSEURS */

  // Assesseur, ressort le nom de l'evenement refuse
  string get_evenement_refuse(){
	return evenement_refuse;
  }

  // Assesseur, ressort l'heure limite de l'evenement refuse
  int get_heure_limite(){
	return heure_limite;
  }

  // Mutateur, change le label de l'evenement refuse
  void set_evenement_refuse(string nom_event){
    evenement_refuse = nom_event;
  }

  // Mutateur, change l'heure limite de l'event refuse
  void set_h_lim(int temps){
    heure_limite = temps;
  }

  /* METHODES */

  // Affiche l'evenement refuse et son heure limite dans le terminal
  void afficher_evenement_refuse(){
    cout<<"evenement refuse = "<<evenement_refuse<<" pendant "<<heure_limite<<endl;
  }

};


////////////////////////////// sous-contrainte c_chronique_event (classe fille)
class c_chronique_event : public contrainte {

private:

  /* ATTRIBUTS */

 string nom_chronique; // nom de la chronique, permet de savoir si le booléen event_verify est
                      // vrai ou faux (déclenchement des chroniques de chroniques)


public:

  /* CONSTRUCTEURS */

  c_chronique_event(string nom_contrainte, string nom_chro):contrainte(nom_contrainte){
    nom_chronique=nom_chro;
  }

  /* ASSESSEURS */

  // Assesseur, ressort le nom de la chronique attendue
  string get_chronique_attendue(){
	return nom_chronique;
  }

  // Mutateur, change le nom de la chronique attendue
  void set_chronique_attendue(string nom_chro){
     nom_chronique = nom_chro;
  }

  /* METHODES */

  // Affiche  nom de la chronique attendue dans le terminal
  void afficher_chronique_attendue(){
    cout<<"nom de la chronique attendue = "<<nom_chronique<<endl;
  }

};

/* FUNCTIONS */


#endif // CONTRAINTE_H_INCLUDED
