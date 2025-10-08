#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) 
{
    vector<int> result(2, 0);
    unordered_map<string, int> um;
    unordered_set<string> us;
    int n = gems.size(), minLength = 1e9;
    for (int i = 0; i < n; ++i)
    {
        us.insert(gems[i]);
    }
    
    int l = 0, r = 0;
    um[gems[r]]++;
    while (r < n && l <= r)
    {
        if (um.size() == us.size())
        {
            if (r - l + 1 < minLength)
            {
                minLength = r - l + 1;
                result[0] = l + 1, result[1] = r + 1;
            }
            
            um[gems[l]]--;
            if (um[gems[l]] == 0)
            {
                um.erase(gems[l]);
            }
            l++;
        }
        else
        {
            r++;
            if (r < n)
            {
                um[gems[r]]++;
            }
        }
    }
    return result;
}