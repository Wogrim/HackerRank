// MD5 hash of an input string

import java.io.*;
import java.util.*;
import java.security.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String input = scan.next();
        scan.close();
        
        MessageDigest md5;
        try{
            md5 = MessageDigest.getInstance("MD5");
           
        }catch (NoSuchAlgorithmException e){
            System.out.println("can't find MD5");
            return;
        }
        
        md5.update(input.getBytes());
        byte[] answer = md5.digest();
        
        StringBuilder sb = new StringBuilder(answer.length * 2);
        for(byte b: answer)
            sb.append(String.format("%02x", b));

        System.out.println(sb.toString());
    }
}
