// BigInteger factorial

using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;
using System.Numerics;

class Result
{

    /////////////////////////
    // MY CODE START

public
    static void extraLongFactorials(int n)
    {
        BigInteger fact = 1;
        while (n > 0)
        {
            fact *= n;
            n--;
        }
        Console.WriteLine(fact);
    }

    // MY CODE END
    /////////////////////////

}

class Solution
{
public
    static void Main(string[] args)
    {
        int n = Convert.ToInt32(Console.ReadLine().Trim());

        Result.extraLongFactorials(n);
    }
}
