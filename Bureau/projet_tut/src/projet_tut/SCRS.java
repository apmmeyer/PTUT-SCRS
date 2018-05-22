package projet_tut;
import java.util.ArrayList;
import java.util.Scanner;

public class SCRS {
	
	public static void main(String[] args) {
		
	
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		ArrayList<Sequence> sequence1 =Parser.parseSequence(str);	
		int i;
		for (i=0; i< sequence1.size(); i++) {
		System.out.println("label : " + sequence1.get(i).getLabel() + " " + "date : " + sequence1.get(i).getDate() );
		}
		
	}
	
	
}
