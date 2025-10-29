using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    int n, m;
    Dictionary<string, int> idxDict = new Dictionary<string, int>();
    List<List<int>> giveReciveInfo = new List<List<int>>(); 
    List<int> giftCnt = new List<int>();
    List<int> nextMonthPresent = new List<int>();
    
    public int solution(string[] friends, string[] gifts) 
    {
        n = friends.Length;
        m = gifts.Length;
        for (int i = 0; i < n; ++i)
        {
            idxDict.Add(friends[i], i);
            giftCnt.Add(0);
            nextMonthPresent.Add(0);
            giveReciveInfo.Add(new List<int>());
            for (int j = 0; j < n; ++j)
            {
                giveReciveInfo[i].Add(0);
            }
        }
        
        for (int i = 0; i < m; ++i)
        {
            string[] part = gifts[i].Split(' ');
            int giveIdx = idxDict[part[0]], receiveIdx = idxDict[part[1]];
            giveReciveInfo[giveIdx][receiveIdx]++;
            giftCnt[giveIdx] += 1;
            giftCnt[receiveIdx] -= 1;
        }
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (giveReciveInfo[i][j] < giveReciveInfo[j][i])
                {
                    nextMonthPresent[j]++;
                }
                else if (giveReciveInfo[j][i] < giveReciveInfo[i][j])
                {
                    nextMonthPresent[i]++;
                }
                else
                {
                    if (giftCnt[i] < giftCnt[j])
                    {
                        nextMonthPresent[j]++;
                    }
                    else if (giftCnt[j] < giftCnt[i])
                    {
                        nextMonthPresent[i]++;
                    }
                }
            }
        }
        return nextMonthPresent.Max();
    }
}