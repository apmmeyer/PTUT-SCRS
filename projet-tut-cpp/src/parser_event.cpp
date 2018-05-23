#include "parser_event.h"

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

