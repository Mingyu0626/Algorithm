#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct coinInfos
{
    int ax, ay, bx, by;
};

template<typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int n, m;
Dim2Vec<char> v;
bool visited[20][20][20][20];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs();


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    bfs();
}

void bfs()
{
    vector<pii> coins;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'o')
            {
                coins.emplace_back(i, j);
            }
        }
    }
    queue<vector<pii>> q;
    q.push(coins);

    int level = 1;
    while (!q.empty() && level < 11)
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            auto curCoins = q.front();
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                vector<pii> newCoins;
                int dropCount = 0;
                for (int k = 0; k < curCoins.size(); k++)
                {
                    int newX = curCoins[k].first + dx[j];
                    int newY = curCoins[k].second + dy[j];
                    if (newX < 0 || n <= newX || newY < 0 || m <= newY)
                    {
                        dropCount++;
                    }
                    else if (v[newX][newY] == '#')
                    {
                        newX = curCoins[k].first;
                        newY = curCoins[k].second;
                    }
                    newCoins.emplace_back(newX, newY);
                }

                if (dropCount == 0)
                {
                    int ax = newCoins[0].first;
                    int ay = newCoins[0].second;
                    int bx = newCoins[1].first;
                    int by = newCoins[1].second;

                    if (!visited[ax][ay][bx][by])
                    {
                        visited[ax][ay][bx][by] = true;
                        q.push(newCoins);
                    }
                }

                else if (dropCount == 1)
                {
                    cout << level;
                    return;
                }
            }
        }
        level++;
    }
    cout << -1;
}