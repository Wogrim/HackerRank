// nothing exciting

import java.util.*;

public class Solution {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int N = scanner.nextInt();
        scanner.close();
        
        if(N%2==1)
            System.out.println("Weird");
        else if(N>20)
            System.out.println("Not Weird");
        else if(N>=6)
            System.out.println("Weird");
        else if(N>=2)
            System.out.println("Not Weird");
    }
}
