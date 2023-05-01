// set of unique permutations

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

 public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        String [] pair_left = new String[t];
        String [] pair_right = new String[t];
        
        for (int i = 0; i < t; i++) {
            pair_left[i] = s.next();
            pair_right[i] = s.next();
        }

    /////////////////////////////////////////
    // MY CODE START
    
    s.close();

    HashSet<String> pairs = new HashSet<>();
    int count = 0;
    for(int i = 0; i < t; i++)
    {
        //store them as a combined string
        if(pairs.add(pair_left[i]+","+pair_right[i]))
            count++;
        System.out.println(count);
    }

    // MY CODE END
    /////////////////////////////////////////

   }
}
