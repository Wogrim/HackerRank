// BigDecimal allows very big floats (and sorting them)

import java.math.BigDecimal;
import java.util.*;
class Solution{
    public static void main(String []args){
        //Input
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        String []s=new String[n+2];
        for(int i=0;i<n;i++){
            s[i]=sc.next();
        }
        sc.close();

        ////////////////////////////////////////
        // MY CODE START

        // java 8+ lets you use a lambda function as a Comparator
        Arrays.sort(s, (String a, String b)->{
            // locked code has some null strings at the end
            // which we want to remain at the end
            if(a==null)
                return 1;
            if(b==null)
                return -1;
            // compare the numbers as BigDecimals, descending order
            BigDecimal A = new BigDecimal(a);
            BigDecimal B = new BigDecimal(b);
            return B.compareTo(A);
        });

        // MY CODE END
        ////////////////////////////////////////

        //Output
        for(int i=0;i<n;i++)
        {
            System.out.println(s[i]);
        }
    }
}