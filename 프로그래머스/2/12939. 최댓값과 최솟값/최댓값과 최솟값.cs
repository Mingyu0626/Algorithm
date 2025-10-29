using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    List<int> v = new List<int>();
    
    public string solution(string s) 
    {
        string[] part = s.Split(' ');
        for (int i = 0; i < part.Length; ++i)
        {
            v.Add(int.Parse(part[i]));
        }
        
        string min = v.Min().ToString(), max = v.Max().ToString();
        
        string result = "";
        result += min;
        result += ' ';
        result += max;
        return result;
    }
}