// using a Stack to match opening/closing brackets

import java.util.*;

class Solution{
    
	// map to lookup the proper matching char for a closing bracket
    private static HashMap<Character,Character> pairs;
    static
    {
        pairs = new HashMap<>();
        pairs.put(')','(');
        pairs.put(']','[');
        pairs.put('}','{');
    }
	
    private static boolean oneLine(String input)
    {
            Stack<Character> stack = new Stack<>();
            for(int i = 0; i < input.length(); i++)
            {
                char c = input.charAt(i);
                switch(c)
                {
                    //opening brackets will be put on a stack
                    case '{':
                    case '[':
                    case '(':
                    stack.push(c);
                    break;
                    
                    //closing brackets will pop the last opening brack off the stack
                    //and make sure they match
                    case ')':
                    case ']':
                    case '}':
                    if(stack.empty() || stack.pop()!=pairs.get(c))
                        return false;
                    break;
                    
                    //unexpected character
                    default:
                    
                }
            }
            //it is balanced if there are no more opening brackets in the stack
            return stack.empty();
    }
    
	public static void main(String []argh)
	{
		Scanner sc = new Scanner(System.in);
		
		while (sc.hasNext()) {
			System.out.println(oneLine(sc.next())?"true":"false");
		}
		sc.close();
	}
}
