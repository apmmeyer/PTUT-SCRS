#include "contrainte.h"

  /* CONSTRUCTEURS */

  // Constructeur simple
  contrainte::contrainte(){
    temps=0;
    type=0;
  }

  // Constructeur évolué, créé la contrainte à partir des données
  contrainte::contrainte(int time, int type_contrainte, string nom_evt){
    temps=time;
    type=type_contrainte;

    // recherche de l'event par nom
    list<event>::iterator it;
	for(it=MES_EVENTS.begin(); it!=MES_EVENTS.end(); it++) {
		if ((*it).get_label() == nom_evt) {
            evenement=(*it);
		}
	}
  }

  /* OPERATEURS */

  contrainte contrainte::operator =(const contrainte &c){
    evenement=c.evenement;
    type=c.type;
    return *this;
  }

  /* ASSESSEURS */

  // Assesseur, ressort le type de la contrainte
  int contrainte::get_type(){
	return type;
  }

  // Assesseur, ressort l'event associé la contrainte
  event contrainte::get_event(){
	return evenement;
  }

  // Assesseur, ressort le temps associé la contrainte
  int contrainte::get_time(){
	return temps;
  }

  // Mutateur, change le nom de la contrainte
  void contrainte::set_type(int type_contrainte){
    type = type_contrainte;
  }

  // Mutateur, change l'event associé à la contrainte
  void contrainte::set_type(event evt){
    evenement = evt;
  }

  /* METHODES */

  // Affiche les datas de la contrainte dans le terminal
  void contrainte::afficher_contrainte(){
    cout<<"contrainte de type : "<<type<<endl;
    cout<<"evenement associe : ";
    evenement.afficher();
    cout<<endl;
  }
