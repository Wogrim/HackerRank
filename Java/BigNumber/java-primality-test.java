// BigInteger has a function to see if a number is probably prime

import java.io.*;
import java.math.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String n = bufferedReader.readLine();
        bufferedReader.close();
        
        BigInteger N = new BigInteger(n);
        System.out.println(N.isProbablePrime(10)?"prime":"not prime");
    }
}
