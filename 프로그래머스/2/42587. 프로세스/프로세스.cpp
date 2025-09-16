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

int solution(vector<int> priorities, int location) 
{
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    int n = priorities.size();
    for (int i = 0; i < n; ++i)
    {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    int cnt = 1;
    while (!q.empty())
    {
        int priority = q.front().first;
        int processNum = q.front().second;
        q.pop();
        if (priority == pq.top())
        {
            if (processNum == location)
            {
                return cnt;
            }
            pq.pop();
            cnt++;
        }
        else
        {
            q.push({priority, processNum});
        }
    }
}