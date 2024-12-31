#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct waters { int a, b, c; };

int volume[3];
int from[6] = { 0, 0, 1, 1, 2, 2 };
int to[6] = { 1, 2, 0, 2, 0, 1 };
vector<vector<bool>> visited(201, vector<bool>(201, false));
vector<bool> result(201, false);
queue<waters> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> volume[0] >> volume[1] >> volume[2];
    visited[volume[0]][volume[1]] = true;
    result[volume[2]] = true;
    q.push({ 0, 0, volume[2] });

    while (!q.empty())
    {
        int curA = q.front().a;
        int curB = q.front().b;
        int curC = q.front().c;
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int cur[3] = { curA, curB, curC };
            int start = from[i], dest = to[i];
            cur[dest] += cur[start];
            cur[start] = 0;
            if (volume[dest] < cur[dest])
            {
                cur[start] = cur[dest] - volume[dest];
                cur[dest] = volume[dest];
            }
            if (!visited[cur[0]][cur[1]])
            {
                visited[cur[0]][cur[1]] = true;
                q.push({ cur[0], cur[1], cur[2] });
                if (cur[0] == 0)
                {
                    result[cur[2]] = true;
                }
            }
        }
    }

    for (int i = 0; i <= 200; i++)
    {
        if (result[i])
        {
            cout << i << ' ';
        }
    }
    return 0;
}