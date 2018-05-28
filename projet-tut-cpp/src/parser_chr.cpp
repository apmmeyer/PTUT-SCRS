#include "parser_chr.h"

/* FUNCTIONS */

// fonction Parseur chroniques
std::list<chronique> parser_chroniques(){

	string maLigne; // temp sur la ligne courante (en lecture)
	string label; // temp sur le nom de la chronique
	int nb_contraintes; // temp sur le nb de contraintes

	int contr_date; // temp sur le contenu d'une contrainte
	int contr_type; // idem
	string contr_nom_event; // idem
    vector<contrainte> vecteur_c; // vecteur temp sur les vecteurs de contrainte

	std::list<chronique> maListe; // temp sur la liste à retourner

    int pos_separateur_1; // position du séparateur ; dans la ligne
    int pos_separateur_2; // position du séparateur : dans la ligne
    int pos_par_1; // position de la parenthese ( dans la ligne
    int pos_par_2; // position de la parenthese ) dans la ligne
    int pos_virg_1; // position de la premiere virgule dans la parenthese courante
    int pos_virg_2; // position de la seconde virgule dans la parenthese courante

    ifstream fichier("./txt/chroniques.txt", ios::in); // ouverture du fichier

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


                // identification des contraintes
                pos_par_1 = pos_separateur_2+1; // premiere parenthese

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
                vecteur_c.clear();
            }

            // instructions
            fichier.close();  // je referme le fichier

    } else {

			// erreur
            cout << "Erreur à l'ouverture !" << endl;

    }

    return maListe;

}


// Affiche la liste des chroniques comme elle apparait dans le fichier chroniques.txt
void afficheur_liste_chr(std::list<chronique> l_chr) {

    list<chronique>::iterator it_chr; // iterateur sur la liste
    for (it_chr = l_chr.begin(); it_chr != l_chr.end() ; it_chr++)
    {
        cout<<(*it_chr).get_nom()<<";"<<(*it_chr).get_contraintes_total()<<":";

        vector<contrainte> vecteur_c = (*it_chr).get_contraintes(); // chargement du vecteur de contrainte
        vector<contrainte>::iterator it_cont; // iterateur sur la contrainte
        for (it_cont = vecteur_c.begin(); it_cont != vecteur_c.end() ; it_cont++) {
            cout<<"("<<(*it_cont).get_event().get_label()<<","<<(*it_cont).get_time()<<","<<(*it_cont).get_type()<<")";
        }
        cout<<endl;
    }
}
