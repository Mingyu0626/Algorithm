#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) 
{
    int n = msg.length();
    unordered_map<string, int> um;
    for (int i = 1; i <= 26; ++i)
    {
        char curChar = 'A' + i - 1;
        string cur = "";
        cur += curChar;
        um[cur] = i;
    }
    
    vector<int> result;
    for (int i = 0; i < n; ++i)
    {
        string curWord = "";
        curWord += msg[i];
        while (um.find(curWord) != um.end() && ++i < n)
        {
            curWord += msg[i];
        }
        
        if (i < n)
        {
            i--;
            string previousWord = curWord;
            previousWord.pop_back();
            result.emplace_back(um[previousWord]);
        }
        else
        {
            result.emplace_back(um[curWord]);
        }
        
        if (um.find(curWord) == um.end())
        {
            int umSize = um.size();
            um[curWord] = umSize + 1;
        }
    }
    return result;
}