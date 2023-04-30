// String.substring() gives the interval [start, end)

import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String S = in.next();
        int start = in.nextInt();
        int end = in.nextInt();
        in.close();
        //substring here
        System.out.println(S.substring(start,end));
    }
}
