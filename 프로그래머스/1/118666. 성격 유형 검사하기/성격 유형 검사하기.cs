using System;
using System.Collections.Generic;

public class Solution 
{
    Dictionary<char, int> scoreDict = new Dictionary<char, int>
    {
        {'R', 0}, {'T', 0},
        {'C', 0}, {'F', 0},
        {'J', 0}, {'M', 0},
        {'A', 0}, {'N', 0}
    };
    
    int n;
    
    public string solution(string[] survey, int[] choices) 
    {
        n = choices.Length;
        for (int i = 0; i < n; ++i)
        {
            if (choices[i] < 4)
            {
                scoreDict[survey[i][0]] += 4 - choices[i];
            }
            else if (4 < choices[i])
            {
                scoreDict[survey[i][1]] += choices[i] - 4;
            }
        }
        
        string result = "";
        result += (scoreDict['R'] < scoreDict['T']) ? 'T' : 'R';
        result += (scoreDict['C'] < scoreDict['F']) ? 'F' : 'C';
        result += (scoreDict['J'] < scoreDict['M']) ? 'M' : 'J';
        result += (scoreDict['A'] < scoreDict['N']) ? 'N' : 'A';
        return result;
    }
}