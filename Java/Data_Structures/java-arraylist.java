// ArrayList does not use [] notation

import java.util.Scanner;
import java.util.ArrayList;

public class Solution {

    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        //empty outer ArrayList with n capacity
        ArrayList<ArrayList<Integer>> nums = new ArrayList<ArrayList<Integer>>(n);

        for(int i = 0; i < n; i++)
        {
            int d = scan.nextInt();
            //empty inner ArrayList with d capacity, put in the outer ArrayList
            nums.add(new ArrayList<Integer>(d));
            //fill the inner ArrayList
            for(int j = 0; j < d; j++)
                nums.get(i).add(scan.nextInt());
        }
        
        int q = scan.nextInt();
        for(int _query = 0; _query < q; _query++)
        {
            int x = scan.nextInt();
            int y = scan.nextInt();
            
            if(y>nums.get(x-1).size() || y<1)
                System.out.println("ERROR!");
            else
                System.out.println(nums.get(x-1).get(y-1));
        }
        
        scan.close();
    }
}
