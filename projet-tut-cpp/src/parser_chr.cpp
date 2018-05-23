#include "parser_chr.h"

/* FONCTIONS */

// fonction Parseur chroniques
std::list<chronique> parser_chroniques(){

	string maLigne; // temp sur la ligne courante (en lecture)
	string label; // temp sur le nom de la chronique
	int nb_contraintes; // temp sur le nb de contraintes
	vector<contrainte> vecteur_c; // temp sur le vecteur de contrainte
	std::list<chronique> maListe; // temp sur la liste à retourner

    ifstream fichier("./txt/chroniques.txt", ios::in); // ouverture du fichier

	// si l'ouverture a réussi
    if(fichier)
    {
			// tant qu'on est pas au bout du fichier
            while(getline(fichier, maLigne))
            {
                /* MANQUE LECTURE DE LIGNE*/
                label="";
                nb_contraintes = 0;

                // envoie les valeurs dans la liste
				maListe.push_back(chronique(label, nb_contraintes, vecteur_c));

            }


            // instructions
            fichier.close();  // je referme le fichier

    } else {

			// erreur
            cout << "Erreur à l'ouverture !" << endl;

    }

    return maListe;
}

