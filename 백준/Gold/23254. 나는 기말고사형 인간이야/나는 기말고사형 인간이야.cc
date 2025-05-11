#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, curUsedTime, result;
vector<pair<int, int>> scoreInfo;
priority_queue<pair<int, int>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    n *= 24;
    scoreInfo.assign(m, {});

    for (int i = 0; i < m; i++)
    {
        cin >> scoreInfo[i].second;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> scoreInfo[i].first;
    }
    for (int i = 0; i < m; i++)
    {
        pq.push(scoreInfo[i]);
    }

    while (curUsedTime < n && !pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        int neededTime = (100 - cur.second) / cur.first;
        int remainScore = (100 - cur.second) % cur.first;
        if (n < curUsedTime + neededTime)
        {
            neededTime = n - curUsedTime;
        }
        cur.second += neededTime * cur.first;
        cur.first = remainScore;
        if (cur.second < 100)
        {
            pq.push(cur);
        }
        else
        {
            result += cur.second;
        }
        curUsedTime += neededTime;
    }

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        result += cur.second;
    }
    cout << result;
    return 0;
}