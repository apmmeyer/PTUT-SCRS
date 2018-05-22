package projet_tut;

import java.util.ArrayList;

import javax.swing.text.Document;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;


public class Parser {
	
	
	public static ArrayList<Sequence> parseSequence(String nameFile){
		ArrayList<Sequence> sequence = new ArrayList<Sequence>();
		try{
			InputStream ips=new FileInputStream(nameFile); 
			InputStreamReader ipsr=new InputStreamReader(ips);
			BufferedReader br=new BufferedReader(ipsr);
			/** Variables declarations **/
			String event;
			double value;
			String line=br.readLine();
			String[] result;

			/** Processing **/
			while (line!=null){
				result=line.split("\\(");
				if(result.length>0){
					result=result[1].split(",");
					event=result[0];
					result=result[1].split("\\)");
					value=Double.parseDouble(result[0]);
					sequence.add(new Sequence(event,value));
				}
				line=br.readLine();
			}		
			br.close(); 
		}		
		catch (Exception e){
			System.out.println(e.toString());
			System.out.println("la séquence n'est pas bien écrite");
		}
		return sequence;
	}
	
	

}
