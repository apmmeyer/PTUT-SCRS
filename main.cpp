/////////////////////////////////////     INCLUDES
#include <iostream>
#include <string>
#include <list>

using namespace std;






//////////////////////////////   CLASSE EVENEMENT  ////////////////////////////////////
class evenement {
    
    int type;
    int nbOccurences;
    list<float> date;
    
public:
    evenement(){
        type = -1;
    }
    
    evenement(int typeN){
        type = typeN;
        nbOccurences = 0;
    }
    
    evenement(int typeN, float instant){
        nbOccurences=1;
        type=typeN;
        date.push_back(instant);
    }
    
    void add_occurrence(float instant){
        nbOccurences++;
        date.push_back(instant);
    }
    
    void set(int typeN){
        type=typeN;
    }

};






////////////////////////////////  CLASSE FLUX D EVENEMENtS  /////////////////////////////
class flux_evts {
    static int nbEvenements;
    list <evenement> flux;
    
public:
    flux_evts(){nbEvenements=0;};
    
    void add_evenement(evenement evt){
        flux.push_back(evt);
    }
    
};






////////////////////////////////   CLASSE CONTRAINTE   ///////////////////////////////////
class contrainte {
    int type;
    list<float> valeurs;
    bool validee;
    float time_validee;
    
public:
    
    contrainte(){type=-1; validee=0;};
    contrainte(int typeN){type=typeN; validee=0;};
    
    void set(int typeN,list<float> valeursN){
        type=typeN;
        valeurs=valeursN;
    }
};







///////////////////////////////  CLASSE CHRONIQUE   ///////////////////////////////////////
class chronique{
    int type;
    list<evenement>  evenements;
    list<contrainte> contraintes;
    
public:
    chronique(int typeN, list<evenement>  evenementsN, list<contrainte> contraintesN){
        type = typeN;
        contraintes = contraintesN;
        evenements  = evenementsN;
    }
    
    ////////  METHODES DE VERIFICATION DES CONTRAINTES
    print(){

    }
    
};


/////////////////////////////////////////      MAIN      ////////////////////////////////////////////////////////////////////////////

int main(int argc, const char * argv[]) {
    
    
    // définition des types d'événements
#define BOUTON          1
#define TEMPERATURE_INF 2
#define TEMPERATURE_SUP 3

    
    
    // définition des types de contraintes
#define EVENEMENT_SIMPLE 0    // A pour t(A) quelconque
#define SUCCESSION       1    // A puis B et t(B)-t(A)
#define SUCCESSION_AVANT 2    // A puis B et t(B)-t(A) < T
    
    
    /////////        définition bibliothèque de chroniques        ///////////
    
    list<contrainte> liste_contraintes;
    list<evenement>  liste_evenements ;
    contrainte* contrainte_ = new contrainte(); // variables de travail pour l'affectation des chroniques
    evenement* evenement_ = new evenement(); // variables de travail pour l'affectation des chroniques
    
    

#define TROP_FROID 1
    // ajout d'une contrainte evenement simple
    contrainte_->set(EVENEMENT_SIMPLE,{});
    liste_contraintes.push_back(*contrainte_);
    // ajout d'un evenement simple à reconnaitre
    evenement_->set(TEMPERATURE_INF);
    liste_evenements.push_back(*evenement_);
    // compilation de la chronique
    chronique * chronique_trop_froid = new chronique(TROP_FROID,liste_evenements,liste_contraintes);
    liste_evenements.erase(liste_evenements.begin(),liste_evenements.end());
    liste_contraintes.erase(liste_contraintes.begin(),liste_contraintes.end());
    
#define TROP_CHAUD 2
    // ajout d'une contrainte evenement simple
    contrainte_->set(EVENEMENT_SIMPLE,{});
    liste_contraintes.push_back(*contrainte_);
    // ajout d'un evenement simple à reconnaitre
    evenement_->set(TEMPERATURE_SUP);
    liste_evenements.push_back(*evenement_);
    // compilation de la chronique
    chronique * chronique_trop_chaud = new chronique(TROP_FROID,liste_evenements,liste_contraintes);
    liste_evenements.erase(liste_evenements.begin(),liste_evenements.end());
    liste_contraintes.erase(liste_contraintes.begin(),liste_contraintes.end());
    

    
    
    
    
    
    
    
    
    
    
    for (int secondes = 0; secondes < 200; secondes++) {
        
        
        
        
        
    }
    
    
    
    
    
    return 0;
}
