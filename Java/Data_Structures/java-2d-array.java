// plain java 2d array

import java.util.Scanner;
import java.io.IOException;

public class Solution {
    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        int[][] nums = new int[6][6];
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                nums[i][j] = scan.nextInt();
            }
        }
        scan.close();
        
        int max = Integer.MIN_VALUE;
        //go through all hourglasses where i,j is the midpoint
        for(int i = 1; i < 5; i++)
        {
            for(int j = 1; j < 5; j++)
            {
                int sum = nums[i-1][j-1]
                        + nums[i-1][j]
                        + nums[i-1][j+1]
                        + nums[i][j]
                        + nums[i+1][j-1]
                        + nums[i+1][j]
                        + nums[i+1][j+1];
                if(sum>max)
                    max = sum;
            }
        }
        System.out.println(max);
    }
}
