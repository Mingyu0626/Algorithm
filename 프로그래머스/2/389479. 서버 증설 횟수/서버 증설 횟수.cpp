#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int n;
queue<pii> q; // {시간, 증설 서버 개수}

int solution(vector<int> players, int m, int k) 
{
    n = players.size();
    int result = 0, serverCount = 0;
    for (int i = 0; i < n; ++i)
    {
        while (!q.empty() && q.front().first + k <= i)
        {
            int returnServerCount = q.front().second;
            serverCount -= returnServerCount;
            q.pop();
        }
        int curCapacity = (serverCount + 1) * m - 1;
        if (curCapacity < players[i])
        {
            int diff = players[i] - curCapacity;
            int addServerCount = diff / m;
            addServerCount += (diff % m != 0) ? 1 : 0;
            result += addServerCount, serverCount += addServerCount;
            q.push({i, addServerCount});
        }
    }
    return result;
}