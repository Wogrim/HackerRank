// looking for subarrays with negative sums

import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] array = new int[n];
        for(int i = 0; i < n; i++)
            array[i] = scan.nextInt();
        scan.close();
        
        //calculate totals
        int[] totals = new int[n];
        totals[0] = array[0];
        for(int i = 1; i < n; i++)
            totals[i] = totals[i-1]+array[i];
        
        //calculate sums of ranges as differences from totals
        int negatives = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(i==0)
                {
                    if(totals[j]<0)
                    {
                        negatives++;
                        // System.out.println(i + " " + j);
                    }
                }
                else if(totals[j]-totals[i-1]<0)
                {
                    negatives++;
                    // System.out.println(i + " " + j);
                }
            }
        }
        System.out.println(negatives);
    }
}
