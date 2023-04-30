// some String stuff

import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        // Scanner.next() looks for next token based on whitespace
        String A=sc.next();
        String B=sc.next();
        sc.close();
        
        // string lengths
        System.out.println(A.length()+B.length());
        // String.compareTo() is used for sorting
        System.out.println(A.compareTo(B)>0?"Yes":"No");
        // capitalize first letter
        System.out.println(
            A.substring(0,1).toUpperCase()
            + A.substring(1)
            + " "
            + B.substring(0,1).toUpperCase()
            + B.substring(1));
    }
}
