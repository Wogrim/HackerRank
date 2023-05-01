// HashMap

import java.util.*;

class Solution{
	public static void main(String []argh)
	{
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		in.nextLine();
        //map names to phone numbers
        HashMap<String,Integer> phonebook = new HashMap<>();
		for(int i=0;i<n;i++)
		{
			String name=in.nextLine();
			int phone=in.nextInt();
			in.nextLine();
            //add key/value to HashMap
            phonebook.put(name, phone);
		}
		while(in.hasNext())
		{
			String name = in.nextLine();
            // check if key in HashMap
            if(phonebook.containsKey(name))
                //get value at key
                System.out.println(name + "=" + phonebook.get(name));
            else
                System.out.println("Not found");
		}
        in.close();
	}
}



