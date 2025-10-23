#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_set>

using namespace std;

int solution(int cacheSize, vector<string> cities) 
{
    int result = 0, n = cities.size();
    
    if (cacheSize == 0)
    {
        return n * 5;
    }
    
    deque<string> dq;
    unordered_set<string> cache;
    for (int i = 0; i < n; ++i)
    {
        string cur = cities[i];
        for (int j = 0; j < cur.length(); j++)
        {
            if ('a' <= cur[j] && cur[j] <= 'z')
            {
                cur[j] -= 32;
            }
        }
        
        result += (cache.find(cur) == cache.end()) ? 5 : 1;
        
        auto it = find(dq.begin(), dq.end(), cur);
        if (it != dq.end())
        {
            dq.erase(it);
        }
        dq.push_back(cur);
        cache.insert(cur);
        
        if (cacheSize < dq.size())
        {
            string temp = dq.front();
            dq.pop_front();
            cache.erase(temp);
        }
    }
    return result;
}