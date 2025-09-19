#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string_view>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <ctime>
#include <bitset>
#include <cstdio>
#include <limits>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>

using namespace std;

priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;
unordered_map<int, int> um;


vector<int> solution(vector<string> v) 
{
    int pqSize = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == "D 1") 
        {
            while (!pq1.empty())
            {
                int cur = pq1.top();
                pq1.pop();
                if (0 < um[cur])
                {
                    um[cur]--;
                    pqSize--;
                    break;
                }
            }
        }
        else if (v[i] == "D -1")
        {
            while (!pq2.empty())
            {
                int cur = pq2.top();
                pq2.pop();
                if (0 < um[cur])
                {
                    um[cur]--;
                    pqSize--;
                    break;
                }
            }
        }
        else
        {
            int num = stoi(v[i].substr(2));
            pq1.push(num), pq2.push(num);
            um[num]++;
            pqSize++;
        }
    }
    
    vector<int> result(2, 0);
    if (0 < pqSize)
    {
        vector<int> leftNums;
        for (auto& a : um)
        {
            if (0 < a.second)
            {
                while (0 < a.second)
                {
                    leftNums.emplace_back(a.first);
                    a.second -= 1;
                }
            }
        }
        result[0] = *max_element(leftNums.begin(), leftNums.end());
        result[1] = *min_element(leftNums.begin(), leftNums.end());
    }
    return result;
}