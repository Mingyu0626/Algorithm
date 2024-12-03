#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, k, s, x, y;
vector<vector<int>> v;
priority_queue<pair<int, pii>> pq;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    v.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
            if (v[i][j] != 0)
            {
                pq.push({ -v[i][j], {i, j} });
            }
        }
    }
    cin >> s >> x >> y;
    bfs();
    cout << v[x - 1][y - 1];
    return 0;
}

void bfs()
{
    int t = 0;
    while (t < s)
    {
        int pqSize = pq.size();
        vector<pair<int, pii>> temp;
        for (int i = 0; i < pqSize; i++)
        {
            int curVirusNum = -pq.top().first;
            int curX = pq.top().second.first;
            int curY = pq.top().second.second;
            pq.pop();
            for (int j = 0; j < 4; j++)
            {
                int newX = curX + dx[j], newY = curY + dy[j];
                if (newX < 0 || n <= newX || newY < 0 || n <= newY) continue;
                if (v[newX][newY] == 0)
                {
                    v[newX][newY] = curVirusNum;
                    temp.push_back({ -curVirusNum, {newX, newY} });
                }
            }
        }
        for (int i = 0; i < temp.size(); i++)
        {
            pq.push(temp[i]);
        }
        t++;
    }
}