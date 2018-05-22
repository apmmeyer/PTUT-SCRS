package projet_tut;
import java.lang.*;
import java.util.ArrayList;
//vi må lage en klasse som søker gjenoom en liste for å finne ut om en kronikk finnes eller ikke. 
//i kronikk klassen "lager vi kronikken" ved å definere navn og dato kronikken ble funnet. 
//vi printer navn og dato, samt hvor mange ganger kronikken har blitt detektert
//
public class chronique {

	private String nom; //nom du chronique
	private boolean event_verify; //si true, le chronice est validé
	private static int nb_validation;  //combien de fois le Chronique à été validé
	private static ArrayList<Sequence> heure_validation = new ArrayList<Sequence>();//liste dynamique avec les heures de validation des chroniques
	//tableau des contraintes pour verifier que c'est bien la chronique 
	//private static final double NB_CONTRAINTES_TOTAL=8;  
	
	//constructeur
	public chronique(String N, int date) {
		nom= N;
		event_verify=false; 
		nb_validation=1;
		heure_validation.add(new Sequence(nom,date)); //add the date into list
		nb_validation ++; //incremente le nombre de fois la validation a eu lieu
	}
	
	
	
	//assesseur pour set un nom du chronique
	public void setNom(String N) {
		nom=N;
	}
	
	//afficher l'heur du chronique
	public static void afficher_heure_validation() {
		for (int i=0; i<heure_validation.size();i++)
		System.out.println("Nom d'evenement : " + heure_validation.get(i).getLabel() +", Date : " + heure_validation.get(i).getDate());
	}
	//afficher le nomble de validations des chroniques 
	public static void afficher_nb_validation() {
		System.out.println("Nombre de chroniques validee: " + nb_validation);
	}
	
}