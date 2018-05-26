#include "chronique.h"

  /* CONSTRUCTEURS */

  // Constructeur simple
  chronique::chronique(){
    nom="";
    event_verify=false;
    nb_validation=0;
    heure_validation.clear();
    nb_contraintes_restantes = 0;
    nb_contraintes_total = 0;
    contraintes.clear();
  }

  // Constructeur évolué, créé la chronique à partir des données
  chronique::chronique(string label, int nb_contraintes, vector<contrainte> vect_contraintes){
    nom=label;
    event_verify=false;
    nb_validation=0;
    heure_validation.clear();
    nb_contraintes_restantes = nb_contraintes;
    nb_contraintes_total = nb_contraintes;
    contraintes = vect_contraintes;
  }

  /* ASSESSEURS */

  // Assesseur, ressort le nom de la chronique
  string chronique::get_nom(){
	return nom;
  }

  // Assesseur, ressort l'état de la chronique (pour les chroniques de chroniques)
  bool chronique::get_event(){
	return event_verify;
  }

  // Assesseur, ressort le nombre de validation
  int chronique::get_nb_valid(){
	return nb_validation;
  }

  // Assesseur, ressort le nombre de contraintes restantes
  int chronique::get_contraintes_restantes(){
	return nb_contraintes_restantes ;
  }


  // Assesseur, ressort le nombre de contraintes totales
  int chronique::get_contraintes_total(){
	return nb_contraintes_total ;
  }


  // Assesseur, ressort le tableau des heures de validation
  std::vector<int> chronique::get_h_valid(){
	return heure_validation;
  }

  // Assesseur, ressort l'heure de la dernière validation
  int chronique::get_last_h_valid(){
	return (*heure_validation.end());
  }

  // Assesseur, ressort le tableau des contraintes
  std::vector<contrainte> chronique::get_contraintes(){
	return contraintes;
  }

  // Mutateur, change la valeur du nombre de contraintes restantes de la chronique
  void chronique::set_contraintes_restantes(int nb){
    nb_contraintes_restantes = nb;
  }

  // Mutateur, change le label de l'élément
  void chronique::set_nom(string name){
    nom = name;
  }

  // Mutateur, change la valeur d'évènement de la chronique
  void chronique::set_event(bool event){
    event_verify = event;
  }

  // Mutateur, change la valeur du nombre de validation de la chronique
  void chronique::set_valid(int nb){
    nb_validation = nb;
  }

  // Mutateur, ajoute une valeur dans les heures de validation de la chronique
  void chronique::set_h_valid(int heure){
    heure_validation.push_back(heure);
  }

  // Reinitialisateur, remet à 0 la valeur du nombre de validation
  void chronique::reset_valid(){
    nb_validation = 0;
  }

  // Reinitialisateur, remet à 0 le tableau des heures de validation
  void chronique::reset_h_valid(){
    heure_validation.clear();
  }

  // Reinitialisateur, remet au maximum la valeur des contraintes restantes à valider
  void chronique::reset_nb_contraintes(){
    nb_contraintes_restantes=nb_contraintes_total;
  }

  // Reinitialisateur, réinitialise tous les attributs
  void chronique::reinit_chronique_all(){
    nom="";
    event_verify=false;
    nb_validation=0;
    heure_validation.clear();
    nb_contraintes_restantes = nb_contraintes_total;
    contraintes.clear();
  }

  /* METHODES */

  // Affiche certains éléments dans la console
  void chronique::afficher(){
    cout<<"nom = "<<nom<<endl;
    cout<<"nombre de validation = "<<nb_validation<<endl;
    if (nb_validation != 0) {
        cout<<"derniere validation = "<<heure_validation.back()<<endl;
    }
    cout<<"evenement detectable = "<<event_verify<<endl;
    cout<<"nombre de contraintes total = "<<nb_contraintes_total<<endl;
    cout<<"nombre de contraintes restantes = "<<nb_contraintes_restantes<<endl;
  }

  // Affiche les heures de validation de la chronique dans le terminal
  void chronique::afficher_heures_validation(){
    vector<int>::iterator it; // iterateur
    for (it = heure_validation.begin(); it != heure_validation.end() ; it++)
    {
        cout<<"validation à "<<(*it)<<endl;
    }
  }

  // Affiche le nombre de fois où la chronique a été terminée
  void chronique::afficher_nb_validation(){
    cout<<"nombre de validation = "<<nb_validation<<endl;
  }

  // Valide la chronique (affiche un message dans le terminal pour annoncer la validation de la chronique,
  // incrémente nb_validation, met à jour heure_validation et passe nb_contraintes_restantes à nb_contraintes_total)
  void chronique::validation_chronique(){
    cout<<"la chronique "<<nom<<" a ete validee"<<endl;
    set_valid(nb_validation+1);
    set_h_valid(HEURE_COURANTE);
    reset_nb_contraintes();
  }


/* FUNCTIONS */

chronique check_validation(chronique chro, event e) {

    // mise a jour de chronique dans la liste des chroniques quand on a trouvé le bon event
    // dans la liste des events (recherche par nom)
    std::vector<contrainte> list_contraintes;
    list_contraintes = chro.get_contraintes();

    // indice represente l'indice du tableau de contrainte
    int indice = (chro.get_contraintes_total()) - (chro.get_contraintes_restantes());

    // affectation des conditions
    bool cond_nom = ((list_contraintes[indice].get_event().get_label()) ==  (e.get_label())); // temp sur la condition sur le nom
    bool cond_temps = ((list_contraintes[indice].get_time()) >=  (e.get_last_h_occur())); // temp sur la condition sur le temps
    bool cond_temps_no_event = ( HEURE_COURANTE >=  ((e.get_last_h_occur())) + (list_contraintes[indice].get_time())); // temp sur la condition sur le temps pour le no event

    switch(list_contraintes[indice].get_type()){

        case 1: // A pour t(A) quelconque

            if (cond_nom) {

                // contrainte validée, on passe à la contrainte suivante
                int nb = chro.get_contraintes_restantes();
                chro.set_contraintes_restantes(nb -1);
            }
            break;

        case 2: // A arrive avant T après le dernier event

            if (cond_nom && cond_temps) {

                // contrainte validée, on passe à la contrainte suivante
                int nb = chro.get_contraintes_restantes();
                chro.set_contraintes_restantes(nb-1);
            }
            break;

        case 3: // Pas d'évènement A depuis le dernier élément pendant un temps T

            if (cond_nom && cond_temps_no_event) {

                // contrainte validée, on passe à la contrainte suivante
                int nb = chro.get_contraintes_restantes();
                chro.set_contraintes_restantes(nb -1);
            }
            break;

        case 4: // A déclenché par une chronique
            /**COMPLETER**/
            break;

        default:
            cout<<"Erreur : type de contrainte inconnu"<<endl;

    }

    // toutes les contraintes ont été validées
    if ((chro.get_contraintes_restantes()) == 0 ) {

        chro.validation_chronique();

    }

    return chro;
}

