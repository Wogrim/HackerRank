// check for end of file with Scanner.hasNext()

import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int i = 0;
        while(s.hasNext())
        {
            i++;
            System.out.println(i + " " + s.nextLine());
        }
        s.close();
    }
}
