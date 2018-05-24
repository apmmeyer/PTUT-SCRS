#include "parser_chr.h"

/* FONCTIONS */

// fonction Parseur chroniques
std::list<chronique> parser_chroniques(){

	string maLigne; // temp sur la ligne courante (en lecture)
	string label; // temp sur le nom de la chronique
	int nb_contraintes; // temp sur le nb de contraintes

	int contr_date; // temp sur le contenu d'une contrainte
	int contr_type; // idem
	string contr_nom_event; // idem
	vector<contrainte> vecteur_c; // temp sur le vecteur de contrainte

	std::list<chronique> maListe; // temp sur la liste à retourner

    int pos_separateur_1; // position du séparateur ; dans la ligne
    int pos_separateur_2; // position du séparateur : dans la ligne
    int pos_par_1; // position de la parenthese ( dans la ligne
    int pos_par_2; // position de la parenthese ) dans la ligne
    int pos_virg_1; // position de la premiere virgule dans la parenthese courante
    int pos_virg_2; // position de la seconde virgule dans la parenthese courante

    ifstream fichier("./txt/chroniques_test.txt", ios::in); // ouverture du fichier

	// si l'ouverture a réussi
    if(fichier)
    {
			// tant qu'on est pas au bout du fichier
            while(getline(fichier, maLigne))
            {

                // cherche la position du ";" dans la ligne
				pos_separateur_1 = maLigne.find(';');

                // cherche la position du ":" dans la ligne
				pos_separateur_2 = maLigne.find(':');

                label=maLigne.substr(0,pos_separateur_1);
                nb_contraintes = std::stoi((maLigne.substr(pos_separateur_1+1,pos_separateur_2-pos_separateur_1-1)));

                pos_par_1 = pos_separateur_2+1; // premiere parenthese

                // identification des contraintes
				for (int j=0;j<nb_contraintes;j++){

                    // recherche des séparateurs
                    pos_virg_1 = maLigne.find_first_of(',',pos_par_1);
                    pos_virg_2 = maLigne.find_first_of(',',pos_virg_1+1);
                    pos_par_2 = maLigne.find_first_of(')',pos_par_1);

                    // affectation des données de la contrainte
                    contr_nom_event = maLigne.substr(pos_par_1+1,pos_virg_1-pos_par_1-1);
                    contr_date = std::stoi((maLigne.substr(pos_virg_1+1,pos_virg_2-pos_virg_1-1)));
                    contr_type = std::stoi((maLigne.substr(pos_virg_2+1,pos_par_2-pos_virg_2-1)));

                    // ajout de la contrainte dans le vecteur contrainte
                    vecteur_c.push_back(contrainte(contr_date,contr_type,contr_nom_event));
                    pos_par_1=pos_par_2+1; // nouvelle parenthese
				}

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
