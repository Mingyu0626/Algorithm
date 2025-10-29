using System;
using System.Collections.Generic;

public class Solution 
{
    private int DateToDays(string date)
    {
        string[] parts = date.Split('.');
        int year = int.Parse(parts[0]);
        int month = int.Parse(parts[1]);
        int day = int.Parse(parts[2]);
        return (year * 12 * 28) + (month * 28) + day;
    }

    public int[] solution(string today, string[] terms, string[] privacies) 
    {
        int todayDays = DateToDays(today);

        Dictionary<char, int> termMap = new Dictionary<char, int>();
        foreach (string term in terms)
        {
            string[] parts = term.Split(' ');
            char type = parts[0][0];
            int month = int.Parse(parts[1]);
            termMap.Add(type, month * 28);
        }

        List<int> destroyList = new List<int>();
        for (int i = 0; i < privacies.Length; i++)
        {
            string[] parts = privacies[i].Split(' ');
            string collectDate = parts[0];
            char type = parts[1][0];         

            if (DateToDays(collectDate) + termMap[type] <= todayDays)
            {
                destroyList.Add(i + 1);
            }
        }
        return destroyList.ToArray();
    }
}