// LinkedList is sometimes useful

import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        
        LinkedList<Integer> list = new LinkedList<>();
        for(int i = 0; i < n; i++)
            list.add(scanner.nextInt());
        
        int q = scanner.nextInt();
        String query;
        for(int i = 0; i < q; i++)
        {
            query = scanner.next();
            
            if(query.equals("Insert"))
                list.add(scanner.nextInt(), scanner.nextInt());
            else if(query.equals("Delete"))
                list.remove(scanner.nextInt());
            else
                System.out.println("Unknown query: " + query);
        }

        scanner.close();
        
        for(int i = 0; i < list.size(); i++)
            System.out.print(list.get(i) + " ");
    }
}
