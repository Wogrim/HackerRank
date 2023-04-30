// remove additional copies of words that are repeated back-to-back, ignore case

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class DuplicateWords {

    public static void main(String[] args) {

        // \b is a word boundary, escape the \
        // \1 is the first captured group aka the first set of parentheses
        String regex = "\\b([a-z]+)\\b( \\1\\b)+";
        Pattern p = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);

        Scanner in = new Scanner(System.in);
        int numSentences = Integer.parseInt(in.nextLine());
        
        while (numSentences-- > 0) {
            String input = in.nextLine();
            
            Matcher m = p.matcher(input);
            
            // replace each whole match with the first group
            while (m.find()) {
                input = input.replaceAll(m.group(0), m.group(1));
            }
            
            System.out.println(input);
        }
        
        in.close();
    }
}

