// BitSet lets you do some binary logic

import java.util.*;

public class Solution {

    public static void main(String[] args) {     
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        
        final int SETS = 2;
        BitSet[] bits = new BitSet[SETS];
        for(int i = 0; i < SETS; i++)
            bits[i] = new BitSet(n);
        
        for(int i = 0; i < m; i++)
        {
            String op = scan.next();
            int first = scan.nextInt();
            int second = scan.nextInt();
            if(op.equals("AND"))
            {
                bits[--first].and(bits[--second]);
            }
            else if(op.equals("OR"))
            {
                bits[--first].or(bits[--second]);
            }
            else if(op.equals("XOR"))
            {
                bits[--first].xor(bits[--second]);
            }
            else if(op.equals("FLIP"))
            {
                bits[--first].flip(second);
            }
            else if (op.equals("SET"))
            {
                bits[--first].set(second);
            }
            
            // BitSet.cardinality() is how many are true
            System.out.println(bits[0].cardinality() + " " + bits[1].cardinality());
        }
        
        scan.close();
    }
}
