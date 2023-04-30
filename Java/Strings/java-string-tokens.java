// splitting a string with a delimiter regex

import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        scan.close();
        
        //can result in empty string at beginning
        String [] separated = s.split("[ !,?._'@]+");
        
        // need to check this before seeing if separated[0] is empty string
        if(separated.length==0)
        {
            System.out.println("0");
            return;
        }
        
        //figure out if first is empty
        int i = 0;
        if(separated[0].equals(""))
            i = 1;
            
        //print number of separated substrings
        System.out.println(separated.length-i);
        
        // loop through the array of separated substrings
        for(;i<separated.length;i++)
            System.out.println(separated[i]);
    }
}

