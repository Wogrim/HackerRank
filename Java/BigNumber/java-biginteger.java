// BigInteger holds numbers that are too big for primitive data types

import java.util.*;
import java.math.BigInteger;

public class Solution {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        BigInteger a = new BigInteger(s.nextLine());
        BigInteger b = new BigInteger(s.nextLine());
        s.close();
        
        // print a+b and a*b
        System.out.println(a.add(b));
        System.out.println(a.multiply(b));
    }
}
