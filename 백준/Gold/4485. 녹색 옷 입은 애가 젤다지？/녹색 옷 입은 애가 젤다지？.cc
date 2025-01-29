#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std; 

int n;
struct info
{ 
    int c, x, y; 
    bool operator<(const info& a) const
    {
        return c > a.c;
    }
};
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int dijkstra(const vector<vector<int>>& v);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cnt = 1;
    while (cin >> n)
    {
        if (n == 0) break;

        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> v[i][j];
            
        cout << "Problem " << cnt << ": " << dijkstra(v) << '\n';
        cnt++;
    }
    return 0;
}

int dijkstra(const vector<vector<int>>& v)
{
    vector<vector<int>> cost(n, vector<int>(n, 1e9));
    priority_queue<info> pq;
    pq.push({v[0][0], 0, 0});
    while (!pq.empty())
    {
        info cur = pq.top();
        pq.pop();
        if (cost[cur.x][cur.y] < cur.c) continue;

        for (int i = 0; i < 4; i++)
        {
            int newX = cur.x + dx[i];
            int newY = cur.y + dy[i];
            if (newX < 0 || n <= newX || newY < 0 || n <= newY) continue;

            int newCost = cur.c + v[newX][newY];
            if (newCost < cost[newX][newY])
            {
                cost[newX][newY] = newCost;
                pq.push({ newCost, newX, newY });
            }
        }
    }
    return cost[n - 1][n - 1];
}