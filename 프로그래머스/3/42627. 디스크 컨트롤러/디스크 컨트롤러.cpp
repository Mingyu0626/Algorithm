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
using pii = pair<int, int>;

struct info
{
    int jobNum, requestTime, requiredTime;
    info(int a, int b, int c)
        :jobNum(a), requestTime(b), requiredTime(c) {}
    
    bool operator<(const info& other) const
    {
        if (requiredTime == other.requiredTime)
        {
            if (requestTime == other.requestTime)
            {
                return jobNum > other.jobNum;
            }
            return requestTime > other.requestTime;
        }
        return requiredTime > other.requiredTime;
    }
};

int solution(vector<vector<int>> jobs) 
{
    int n = jobs.size();
    vector<pii> v(n);
    for (int i = 0; i < n; ++i)
    {
        v[i] = {jobs[i][0], jobs[i][1]};
    }
    sort(v.begin(), v.end());
    
    priority_queue<info> pq;
    long long curTime = 0, turnaroundTime = 0;
    int jobIdx = 0;
    while (jobIdx < n || !pq.empty())
    {
        while (jobIdx < n && v[jobIdx].first <= curTime)
        {
            pq.push({jobIdx, v[jobIdx].first, v[jobIdx].second});
            jobIdx++;
        }
        if (jobIdx < n && pq.empty())
        {
            curTime = v[jobIdx].first;
            pq.push({jobIdx, v[jobIdx].first, v[jobIdx].second});
            jobIdx++;
        }
        
        info cur = pq.top();
        pq.pop();
        
        curTime += cur.requiredTime;
        turnaroundTime += (curTime - cur.requestTime);
    }
    return turnaroundTime / n;
}