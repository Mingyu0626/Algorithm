#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int f, s, g, u, d, result;
vector<bool> visited;

void bfs(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> f >> s >> g >> u >> d;
    visited.assign(f + 1, false);
    bfs(s);
    return 0;
}

void bfs(int start)
{
    queue<pair<int, int>> q;
    q.push({ start, 0 });
    visited[start] = true;
    while (!q.empty())
    {
        int curFloor = q.front().first;
        int curButton = q.front().second;
        q.pop();

        if (curFloor == g)
        {
            cout << curButton;
            return;
        }
        int newFloor = curFloor + u;
        if (newFloor <= f && !visited[newFloor])
        {
            q.push({ newFloor, curButton + 1 });
            visited[newFloor] = true;
        }
        
        newFloor = curFloor - d;
        if (1 <= newFloor && !visited[newFloor])
        {
            q.push({ newFloor, curButton + 1 });
            visited[newFloor] = true;
        }
    }
    cout << "use the stairs";
    return;
}