// simple regex validation

import java.util.Scanner;

/////////////////////////////
// MY CODE START

class UsernameValidator {
    //^ is start of string
    //[a-zA-Z] is any letter
    //\w is any letter, digit, or underscore
    //{7,29} is 7-29 times
    //$ is end of string
    public static final String regularExpression = "^[a-zA-Z]\\w{7,29}$";
}

// MY CODE END
/////////////////////////////

public class Solution {
    private static final Scanner scan = new Scanner(System.in);
    
    public static void main(String[] args) {
        int n = Integer.parseInt(scan.nextLine());
        while (n-- != 0) {
            String userName = scan.nextLine();

            if (userName.matches(UsernameValidator.regularExpression)) {
                System.out.println("Valid");
            } else {
                System.out.println("Invalid");
            }           
        }
    }
}