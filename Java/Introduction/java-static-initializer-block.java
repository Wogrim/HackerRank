// check for end of file with Scanner.hasNext()

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    //////////////////////////////////////////////////
    // MY CODE START
    
    private static int B;
    private static int H;
    private static boolean flag;
    // this is run when the class is loaded
    static {
        Scanner s = new Scanner(System.in);
        B = s.nextInt();
        H = s.nextInt();
        s.close();
        if(B<=0 || H<=0)
        {
            flag = false;
            System.out.println("java.lang.Exception: Breadth and height must be positive");
        }
        else
            flag = true;
    }

// MY CODE END
//////////////////////////////////////////////////
public static void main(String[] args){
		if(flag){
			int area=B*H;
			System.out.print(area);
		}
		
	}//end of main

}//end of class


