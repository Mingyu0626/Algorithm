#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
using pii = pair<int, int>;

int n, m;
map<int, int> laddersAndSnakes;
vector<int> visited(101, 1e9);

void bfs(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int s, e;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        laddersAndSnakes[s] = e;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        laddersAndSnakes[s] = e;
    }

    bfs(1);
    cout << visited[100];
    return 0;
}

void bfs(int start)
{
    visited[start] = 0;
    queue<pii> q;
    q.push({ 1, 0 });
    while (!q.empty())
    {
        int curPoint = q.front().first;
        int curDiceRolls = q.front().second;
        q.pop();

        if (visited[curPoint] < curDiceRolls) continue;

        int nextPoint;
        int nextDiceRolls = curDiceRolls + 1;
        for (int i = 1; i <= 6; i++)
        {
            nextPoint = curPoint + i;
            if (nextPoint <= 100 && nextDiceRolls < visited[nextPoint])
            {
                if (laddersAndSnakes.find(nextPoint) != laddersAndSnakes.end())
                {
                    int teleportPoint = laddersAndSnakes[nextPoint];
                    if (nextDiceRolls < visited[teleportPoint])
                    {
                        q.push({ teleportPoint, nextDiceRolls });
                        visited[teleportPoint] = nextDiceRolls;
                    }
                }
                else
                {
                    q.push({ nextPoint, nextDiceRolls });
                    visited[nextPoint] = nextDiceRolls;
                }
            }
        }
    }
}