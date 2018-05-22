package projet_tut;
import projet_tut.chronique;
import java.util.ArrayList;
//test pour voir les fonctionnements. À mettre dans la pobelle
public class test {
	public static void main(String[] argv) {
		chronique my_chronique=new chronique("Entrer_dans_salon",100);
		chronique my_chronique2=new chronique("Entrer_dans_SDB",200);
		
		chronique.afficher_heure_validation();
		chronique.afficher_nb_validation();
		
		
	}
}
