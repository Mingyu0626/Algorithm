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

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    int n = progresses.size();
    queue <pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    {
        q.push({progresses[i], speeds[i]});
    }
    
    vector<int> result;
    while (!q.empty())
    {
        if (100 <= q.front().first)
        {
            result.emplace_back(1);
            q.pop();
            while (!q.empty() && 100 <= q.front().first)
            {
                result[result.size() - 1]++;
                q.pop();
            }
        }
        else
        {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i)
            {
                pair<int, int> cur = q.front();
                q.pop();
                q.push({cur.first + cur.second, cur.second});
            }
        }
    }
    

    return result;
}