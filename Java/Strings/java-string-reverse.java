// check if string is a palindrome by checking against reverse

import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        sc.close();
        
        String reverse = "";
        for(int i = A.length()-1; i >= 0; i--)
            reverse += A.charAt(i);

        // String.equals() to compare letters
        System.out.println(A.equals(reverse)? "Yes" : "No");
    }
}

