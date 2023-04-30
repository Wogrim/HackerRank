// comparing substrings of size k

import java.util.Scanner;

public class Solution {

    public static String getSmallestAndLargest(String s, int k) {
        String smallest = "";
        String largest = "";
        
        ///////////////////////////////////////////////
        // MY CODE START

        String current = s.substring(0,k);
        smallest = largest = current;
        for(int i = 1; i < s.length()-k+1; i++)
        {
            current = s.substring(i,i+k);
            if(current.compareTo(smallest)<0)
                smallest = current;
            if(current.compareTo(largest)>0)
                largest = current;
        }
        
        // MY CODE END
        ///////////////////////////////////////////////

        return smallest + "\n" + largest;
    }


    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int k = scan.nextInt();
        scan.close();
      
        System.out.println(getSmallestAndLargest(s, k));
    }
}