using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public string solution(string s) 
    {
        bool prevIsSpace = true;
        string result = "";
        for (int i = 0; i < s.Length; ++i)
        {
            if (s[i] == ' ')
            {
                prevIsSpace = true;
                result += s[i];
            }
            else
            {
                if (prevIsSpace && ('a' <= s[i] && s[i] <= 'z'))
                {
                    result += (char)(s[i] - 32);
                }
                else if (!prevIsSpace && ('A' <= s[i] && s[i] <= 'Z'))
                {
                    result += (char)(s[i] + 32);
                }
                else
                {
                    result += s[i];
                }
                prevIsSpace = false;
            }
        }
        return result;
    }
}