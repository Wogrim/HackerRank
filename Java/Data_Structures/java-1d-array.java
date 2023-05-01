// a dynamic programming style of checking if a square is reachable

import java.util.*;

public class Solution {

    public static boolean canWin(int leap, int[] game) {
        /////////////////////////////////////////
        // MY CODE START
        
        int n = game.length;
        
        //if we can't leap, all cells must have a 0 for us to win
        if(leap <= 1)
        {
            for(int i = 1; i < n; i++)
                if(game[i]!=0)
                    return false;
            
            return true;
        }
        
        //can jump off the end from the first cell
        if(leap>=n)
            return true;
        
        boolean[] reachable = new boolean[n];
        reachable[0] = true;
        //start at 2nd cell to simplify walk forward check;
        //need to check jump off from first cell
        for(int i = 1; i < n; i++)
        {
            // System.out.println(reachable[i]);
            // reachable[i] = false;
            if(game[i]==0)
            {
                //can leap to this cell
                if(i>=leap && reachable[i-leap])
                    reachable[i] = true;
                //can walk forward to this cell
                else if(reachable[i-1])
                    reachable[i] = true;       
            }
            //walkback if reachable
            if(reachable[i])
            {
                for(int j = i-1; j >= 0; j--)
                    if(!reachable[j] && game[j]==0)
                        reachable[j]=true;
                    else 
                        break;
            }
            //can jump off the end
            if(reachable[i] && i+leap>=n)
                return true;
        }
        
        return false;
        
        // MY CODE END
        /////////////////////////////////////////
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int q = scan.nextInt();
        while (q-- > 0) {
            int n = scan.nextInt();
            int leap = scan.nextInt();
            
            int[] game = new int[n];
            
            for (int i = 0; i < n; i++) {
                game[i] = scan.nextInt();
            }

            System.out.println( (canWin(leap, game)) ? "YES" : "NO" );
        }
        scan.close();
    }
}
