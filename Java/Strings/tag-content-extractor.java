// getting contents between a starting and ending tag

import java.util.*;
import java.util.regex.*;

public class Solution{
    // "<([^>]+)>" is the starting tag
    // "([^<>]+)" is everything between if no other tags
    // "</\\1>" is the corresponding ending tag
    private static Pattern p = Pattern.compile("<([^>]+)>([^<>]+)</\\1>");
    
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int testCases = Integer.parseInt(in.nextLine());
		while(testCases>0){
			String line = in.nextLine();
			
            Matcher m = p.matcher(line);
            
            int count = 0;
            while(m.find())
            {
                // print the stuff between the tags
                System.out.println(m.group(2));
                count++;
            }
            
            if(count==0)
                System.out.println("None");
			
			testCases--;
		}
        in.close();
	}
}
