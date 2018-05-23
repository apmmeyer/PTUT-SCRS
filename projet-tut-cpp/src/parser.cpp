#include "parser.h"

/* FONCTIONS */

// fonction Parseur
std::vector<elmt_sequence> parser(){

	int pos_separateur; // position du séparateur dans la ligne
	string maLigne; // temp sur la ligne courante (en lecture)
	std::vector<elmt_sequence> maSequence; // temp sur la séquence à retourner

    ifstream fichier("./txt/sequence.txt", ios::in); // ouverture du fichier

	// si l'ouverture a réussi
    if(fichier)
    {
			// tant qu'on est pas au bout du fichier
            while(getline(fichier, maLigne))
            {
                // cherche la position du ";" dans la ligne
				pos_separateur = maLigne.find(';');

                // envoie les valeurs dans la séquence
				maSequence.push_back(elmt_sequence(maLigne.substr(1,pos_separateur-1),std::stoi((maLigne.substr(pos_separateur+1,maLigne.length()-pos_separateur-2)))));

            }


            // instructions
            fichier.close();  // je referme le fichier

    } else {

			// erreur
            cout << "Erreur à l'ouverture !" << endl;

    }

    return maSequence;
}

