#include "sequence.h"

  /* CONSTRUCTEURS */

  // Constructeur nul
  elmt_sequence::elmt_sequence(){
    label="";
    date=-1;
  }

  // Constructeur �volu�, cr�� l'�l�ment � partir des donn�es
  elmt_sequence::elmt_sequence(string name, int d){
    label=name;
    date=d;
  }

  /* ASSESSEURS */

  // Assesseur, ressort le label de l'�l�ment
  string elmt_sequence::get_label(){
	return label;
  }

  // Assesseur, ressort la date de l'�l�ment
  int elmt_sequence::get_date(){
	return date;
  }

  // Mutateur, change le label de l'�l�ment
  void elmt_sequence::set_label(string name){
    label = name;
  }

  // Mutateur, change la date de l'�l�ment
  void elmt_sequence::set_date(int time){
    date = time;
  }

  /* METHODES */

  // Affiche l'�l�ment dans la console
  void elmt_sequence::afficher(){
    cout<<"label = "<<label<<endl;
    cout<<"date = "<<date<<endl;
  }
