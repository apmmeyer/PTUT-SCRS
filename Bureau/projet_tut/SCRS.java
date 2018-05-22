package projet_tut;
import java.util.ArrayList;



public class SCRS {

	public static void main(String[] args) {
		ArrayList<Sequence> sequence1 =Parser.parseSequence(args[0]);
		System.out.println("label" + sequence1.get(1).getLabel() + "date" + sequence1.get(1).getDate() );
	}
	
	
}
