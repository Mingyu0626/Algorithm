using System;
using System.Collections.Generic;

public class Solution 
{
    Dictionary<string, HashSet<string>> reportDict = new Dictionary<string, HashSet<string>>();
    Dictionary<string, int> userIdxDict = new Dictionary<string, int>();
    int n, m;
    
    public int[] solution(string[] id_list, string[] report, int k) 
    {
        n = id_list.Length; 
        m = report.Length;
        List<int> result = new List<int>();
        for (int i = 0; i < n; ++i)
        {
            reportDict.Add(id_list[i], new HashSet<string>());
            userIdxDict.Add(id_list[i], i);
            result.Add(0);
        }
        for (int i = 0; i < m; ++i)
        {
            string[] part = report[i].Split(' ');
            HashSet<string> hs = reportDict[part[1]];
            hs.Add(part[0]);
        }
        
        foreach (var a in reportDict)
        {
            if (k <= a.Value.Count)
            {
                foreach (var userName in a.Value)
                {
                    result[userIdxDict[userName]]++;
                }
            }
        }
        return result.ToArray();
    }
}