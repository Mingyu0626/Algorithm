using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    Dictionary<int, int> dict = new Dictionary<int, int>();
    
    public int solution(int k, int[] tangerine) 
    {
        for (int i = 0; i < tangerine.Length; ++i)
        {
            if (dict.ContainsKey(tangerine[i]))
            {
                dict[tangerine[i]]++;
            }
            else
            {
                dict.Add(tangerine[i], 1);
            }
        }
        List<int> result = new List<int>();
        foreach (var a in dict)
        {
            result.Add(a.Value);
        }
        result.Sort((a, b) => b.CompareTo(a));
        int answer = 0, cur = 0;
        for (int i = 0; i < result.Count; ++i)
        {
            answer++;
            cur += result[i];
            if (k <= cur)
            {
                break;
            }
        }
        return answer;
    }
}