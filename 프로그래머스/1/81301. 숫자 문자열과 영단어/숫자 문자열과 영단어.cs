using System;
using System.Collections.Generic;

public class Solution 
{
    int n;
    Dictionary<string, char> d = new Dictionary<string, char>
    {
        {"zero", '0'}, {"one", '1'}, {"two", '2'}, {"three", '3'},  {"four", '4'},
        {"five", '5'}, {"six", '6'}, {"seven", '7'}, {"eight", '8'},  {"nine", '9'}
    };
    
    public int solution(string s) 
    {
        n = s.Length;
        string result = "";
        string cur = "";
        for (int i = 0; i < n; ++i)
        {
            if ('0' <= s[i] && s[i] <= '9')
            {
                result += s[i];
            }
            else
            {
                cur += s[i];
                if (d.TryGetValue(cur, out char val))
                {
                    result += val;
                    cur = "";
                }
            }
        }
        return int.Parse(result);
    }
}