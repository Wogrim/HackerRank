// check if 2 strings are anagrams of eachother

import java.util.Scanner;

public class Solution {

    /////////////////////////////////////////////
    // MY CODE START

    static boolean isAnagram(String a, String b) {
        // early exit if not the same length
        if(a.length()!=b.length())
            return false;
        
        // case-insensitive
        a = a.toLowerCase();
        b = b.toLowerCase();
        
        // difference in counts for each letter
        int[] diffs = new int[26];
        for(int i = 0; i < a.length(); i++)
        {
            diffs[a.charAt(i)-'a']++;
            diffs[b.charAt(i)-'a']--;
        }
        
        // anagram only if all diffs are 0
        for(int i = 0; i < diffs.length; i++)
        {
            if(diffs[i]!=0)
                return false;
        }
        return true;
    }

    // MY CODE END
    /////////////////////////////////////////////

    public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}