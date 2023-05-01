// a singleton only allows one of itself to exist

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.reflect.*;


class Singleton{
    private Singleton(){}
    public String str;
    private static Singleton one;
    public static Singleton getSingleInstance(){
        if(one==null)
            one = new Singleton();
        return one;
    }
}

// hidden code uses the singleton
