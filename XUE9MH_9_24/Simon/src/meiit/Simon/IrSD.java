package meiit.Simon;

import java.io.*;
import java.util.*;

public class IrSD {
	
	

	public static void main(String[] args) {
		int db = 0;
		System.out.println("Kerem az beolvasando szamok darabszamat.");
		Scanner input = new Scanner(System.in);
		db = input.nextInt();
		int[] array = new int[db];
		System.out.println("Kerem a szamokat!");
		for(int i = 0 ; i < db ; i++) {
			while(!input.hasNextInt())  
	          {
	          	System.out.println("Ez nem szam");
	            input.next();
	          }
			array[i]=input.nextInt();
		}

	}

}
