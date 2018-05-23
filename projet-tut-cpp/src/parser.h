/*

UTILISATION DU PARSEUR

- Le fichier des séquences doit s'appeler "sequence.txt et se trouver à l'adresse "./txt/".
- La syntaxe pour chaque couple label-date est exactement : (label;date)
- Chaque couple est séparé par un retour à la ligne

*/

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

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
  elmt_sequence(){
    label="";
    date=-1;
  }

  // Constructeur évolué, créé l'élément à partir des données
  elmt_sequence(string name, int d){
    label=name;
    date=d;
  }

  /* ASSESSEURS */

  // Assesseur, ressort le label de l'élément
  string get_label(){
	return label;
  }

  // Assesseur, ressort la date de l'élément
  int get_date(){
	return date;
  }

  // Mutateur, change le label de l'élément
  void set_label(string name){
    label = name;
  }

  // Mutateur, change la date de l'élément
  void set_date(int time){
    date = time;
  }

  /* METHODES */

  // Affiche l'élément dans la console
  void afficher(){
    cout<<"label = "<<label<<endl;
    cout<<"date = "<<date<<endl;
  }


};

/* FUNCTIONS */

std::vector<elmt_sequence> parser(); // Parseur : traduit sequence.txt en sequence interpretable

#endif
