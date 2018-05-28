#ifndef SEQUENCE_H_INCLUDED
#define SEQUENCE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/* CLASSES */

// Element unitaire de la sequence
class elmt_sequence {
private:

    /* ATTRIBUTS */

    string label;
    int date;

public:

  /* CONSTRUCTEURS */

  // Constructeur nul
  elmt_sequence();

  // Constructeur évolué, créé l'élément à partir des données
  elmt_sequence(string name, int d);

  /* ASSESSEURS */

  // Assesseur, ressort le label de l'élément
  string get_label();

  // Assesseur, ressort la date de l'élément
  int get_date();

  // Mutateur, change le label de l'élément
  void set_label(string name);

  // Mutateur, change la date de l'élément
  void set_date(int time);

  /* METHODES */

  // Affiche l'élément dans la console
  void afficher();


};

#endif // SEQUENCE_H_INCLUDED
