#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int M = 65536;
string temp;

int solution(string str1, string str2) 
{
    unordered_map<string, int> um1, um2, unionUm, intersectionUm;
    
    for (int i = 0; i < str1.length(); ++i)
    {
        char c = str1[i];
        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
        {
            temp += ('a' <= c) ? c - 32 : c;
            if (temp.length() == 2)
            {
                um1[temp]++;
                temp = ('a' <= c) ? c - 32 : c;
            }
        }
        else
        {
            temp = "";
        }
    }
    
    temp = "";
    for (int i = 0; i < str2.length(); ++i)
    {
        char c = str2[i];
        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
        {
            temp += ('a' <= c) ? c - 32 : c;
            if (temp.length() == 2)
            {
                um2[temp]++;
                temp = ('a' <= c) ? c - 32 : c;
            }
        }
        else
        {
            temp = "";
        }
    }
    
    float unionSize = 0, intersectionSize = 0;
    for (const auto& a : um1)
    {
        if (um2.find(a.first) != um2.end())
        {
            unionUm[a.first] = max(um1[a.first], um2[a.first]);
            unionSize += max(um1[a.first], um2[a.first]);
            intersectionUm[a.first] = min(um1[a.first], um2[a.first]);
            intersectionSize += min(um1[a.first], um2[a.first]);
        }
        else
        {
            unionUm[a.first] = um1[a.first];
            unionSize += um1[a.first];
        }
    }
    
    for (const auto& a : um2)
    {
        if (um1.find(a.first) == um1.end())
        {
            unionUm[a.first] = um2[a.first];
            unionSize += um2[a.first];
        }
    }
    
    if (unionSize == 0)
    {
        return M;
    }
    return (int)(intersectionSize / unionSize * M);
}