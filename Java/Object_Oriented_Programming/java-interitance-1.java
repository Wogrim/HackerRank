// bird is an animal; can walk(), use keyword 'extends'

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Animal{
	void walk()
	{
		System.out.println("I am walking");
	}
}
class Bird extends Animal
{
	void fly()
	{
		System.out.println("I am flying");
	}
    
    //////////////////////////////
    // MY CODE START

    void sing()
    {
        System.out.println("I am singing");
    }

    // MY CODE END
    //////////////////////////////
}

public class Solution{

   public static void main(String args[]){

	  Bird bird = new Bird();
	  bird.walk();
	  bird.fly();
      bird.sing();
	
   }
}