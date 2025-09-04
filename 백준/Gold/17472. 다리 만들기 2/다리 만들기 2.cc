#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int n, m, numOfIslands, numOfBridges, result;
Dim2Vec<int> v;
Dim2Vec<pii> bridges;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void countIsland();
void bfs(int x, int y, Dim2Vec<bool>& visited);
bool isValid(const int& x, const int& y);
void makeAllBridge();
void tryMakeBridge(int x, int y, int dir, int startIslandNum, int bridgeLength);
void prim(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> v[i][j];
        }
    }
    countIsland();
    makeAllBridge();
    prim(1);
    return 0;
}

void countIsland()
{
    Dim2Vec<bool> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (v[i][j] == 1 && !visited[i][j])
            {
                bfs(i, j, visited);
            }
        }
    }
    bridges.assign(numOfIslands + 1, vector<pii>());

}

void bfs(int x, int y, Dim2Vec<bool>& visited)
{
    numOfIslands++;
    visited[x][y] = true;
    queue<pii> q;
    q.push({ x, y });
    while (!q.empty())
    {
        int curX = q.front().first, curY = q.front().second;
        v[curX][curY] = numOfIslands;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i], newY = curY + dy[i];
            if (isValid(newX, newY) && v[newX][newY] == 1 && !visited[newX][newY])
            {
                q.push({ newX, newY });
                visited[newX][newY] = true;
            }
        }
    }
}

bool isValid(const int& x, const int& y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}

void makeAllBridge()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (v[i][j] != 0)
            {
                for (int dir = 0; dir < 4; dir++)
                {
                    tryMakeBridge(i + dx[dir], j + dy[dir], dir, v[i][j], 0);
                }
            }
        }
    }
}

void tryMakeBridge(int x, int y, int dir, int startIslandNum, int bridgeLength)
{
    if (!isValid(x, y))
    {
        return;
    }

    if (v[x][y] != 0 && v[x][y] != startIslandNum && 1 < bridgeLength)
    {
        bridges[startIslandNum].emplace_back(bridgeLength, v[x][y]);
        return;
    }

    if (v[x][y] == 0)
    {
        tryMakeBridge(x + dx[dir], y + dy[dir], dir, startIslandNum, bridgeLength + 1);
    }
}

void prim(int start)
{
    vector<bool> visited(numOfIslands + 1, false);
    visited[start] = true;
    priority_queue<pii> pq;
    for (int i = 0; i < bridges[start].size(); i++)
    {
        int nextCost = bridges[start][i].first;
        int nextNode = bridges[start][i].second;
        pq.push({ -nextCost, nextNode });
    }

    int mstSize = 1;
    while (!pq.empty())
    {
        int curCost = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (!visited[curNode])
        {
            mstSize++;
            result += curCost;
            visited[curNode] = true; 
        }

        if (mstSize == numOfIslands)
        {
            cout << result;
            return;
        }

        for (int i = 0; i < bridges[curNode].size(); i++)
        {
            int nextCost = bridges[curNode][i].first;
            int nextNode = bridges[curNode][i].second;
            if (!visited[nextNode])
            {
                pq.push({ -nextCost, nextNode });
            }
        }
    }
    cout << -1;
}