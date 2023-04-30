// regex for IPv4 addresses allowing leading zeros up to 3 digits total

import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Scanner;

class Solution{

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            String IP = in.next();
            System.out.println(IP.matches(new MyRegex().pattern));
        }

    }
}

//////////////////////////////////////////
// MY CODE START

class MyRegex{
    // 0-9
    // 00-99
    // 000-199
    // 200-249
    // 250-255
    public String pattern = "^(([0-9]|[0-9][0-9]|[0-1][0-9][0-9]|[2][0-4][0-9]|[2][5][0-5])[.]){3}"
                           + "([0-9]|[0-9][0-9]|[0-1][0-9][0-9]|[2][0-4][0-9]|[2][5][0-5])$";
}
