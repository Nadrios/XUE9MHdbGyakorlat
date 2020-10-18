package meiit.Simon;

import java.io.*;
import java.util.*;
import java.lang.*;

public class OlvasSD {
	
	public static int intRead(FileReader bs) throws IOException{
		StringBuffer sz = new StringBuffer(12);
		int b;
		do {
			b = bs.read();	
			if((char)b != ',')
				sz.append((char)b);
			else
				break;
		} while (true);
		return Integer.parseInt(sz.toString());
	}
	
	public static void main(String[] args) throws IOException {
		File inputFile = new File("Simon.txt");
		FileReader be_stream = new FileReader(inputFile);
		int db;
		db = intRead(be_stream);
		System.out.println("Adatok szama = " + db);
		
		int[] array = new int[db];
		int sum = 0;
		for(int i = 0 ; i < db ; i++) {
			array[i]=intRead(be_stream);
			System.out.println(i + ".adat = " + array[i]);
			sum+=array[i];
		}
		System.out.println("Osszeg: " + sum);
		be_stream.close();
	}

}
