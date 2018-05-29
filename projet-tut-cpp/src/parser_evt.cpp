#include "parser_evt.h"

/* FONCTIONS */

// fonction Parseur evenements
std::list<event> parser_evenements(){

	string maLigne; // temp sur la ligne courante (en lecture)
	std::list<event> maListe; // temp sur la liste à retourner

    string label; // temp sur le nom de l'evenement

    ifstream fichier("./txt/events.txt", ios::in); // ouverture du fichier

	// si l'ouverture a réussi
    if(fichier)
    {
			// tant qu'on est pas au bout du fichier
            while(getline(fichier, maLigne))
            {

                label=maLigne;

                // envoie les valeurs dans la liste
				maListe.push_back(event(label));

            }


            // instructions
            fichier.close();  // je referme le fichier

    } else {

			// erreur
            cout << "Erreur à l'ouverture !" << endl;

    }

    return maListe;
}

// Affiche la liste des evenements comme elle apparait dans le fichier events.txt
void afficheur_liste_evt(std::list<event> l_evt) {

    list<event>::iterator it_evt; // iterateur
    for (it_evt = l_evt.begin(); it_evt != l_evt.end() ; it_evt++)
    {
        cout<<(*it_evt).get_label()<<endl;

    }

}

