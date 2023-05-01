// SHA-256 hash of a string

import java.io.*;
import java.util.*;
import java.security.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String input = scan.next();
        scan.close();
        
        MessageDigest md_sha256;
        try{
            md_sha256 = MessageDigest.getInstance("SHA-256");
        } catch (NoSuchAlgorithmException e)
        {
            throw new RuntimeException(e);
        }
        
        md_sha256.update(input.getBytes());
        byte[] answer = md_sha256.digest();
        for( byte b : answer)
            System.out.printf("%02x", b);
    }
}
