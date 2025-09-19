#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct info
{
    int jobNum, requestTime, requiredTime;

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
    sort(jobs.begin(), jobs.end());

    priority_queue<info> pq;
    long long curTime = 0;
    long long totalTurnaroundTime = 0;
    int jobIdx = 0;
    
    while (jobIdx < n || !pq.empty())
    {
        while (jobIdx < n && jobs[jobIdx][0] <= curTime)
        {
            pq.push({jobIdx, jobs[jobIdx][0], jobs[jobIdx][1]});
            jobIdx++;
        }

        if (!pq.empty())
        {
            info cur = pq.top();
            pq.pop();
            
            curTime += cur.requiredTime;
            totalTurnaroundTime += (curTime - cur.requestTime);
        }
        else
        {
            curTime = jobs[jobIdx][0];
        }
    }
    
    return totalTurnaroundTime / n;
}