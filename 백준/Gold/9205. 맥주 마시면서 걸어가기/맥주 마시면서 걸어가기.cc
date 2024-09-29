#define first x
#define second y
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int t, n;
pii s, e;
vector<pii> c;
bool isHappy;
bool visited[101];

void bfs(int x, int y);


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t > 0)
    {
        cin >> n >> s.x >> s.y;
        c.assign(n, { 0, 0 });
        fill(visited, visited + 101, false);
        isHappy = true;
        for (int i = 0; i < n; i++) cin >> c[i].x >> c[i].y;
        cin >> e.x >> e.y;

        bfs(s.x, s.y);
        if (!isHappy) cout << "sad\n";
        else cout << "happy\n";
        t--;
    }
}

void bfs(int x, int y)
{
    queue<pii> q;
    q.push({ x, y });
    while (!q.empty())
    {
        int curX = q.front().x;
        int curY = q.front().y;
        q.pop();

        int festivalDist = abs(e.x - curX) + abs(e.y - curY);
        if (festivalDist <= 1000) return;
        
        for (int i = 0; i < n; i++)
        {
            int dist = abs(c[i].x - curX) + abs(c[i].y - curY);
            if (dist <= 1000 && !visited[i])
            {
                visited[i] = true;
                q.push({ c[i].x, c[i].y });
            }
        }
    }
    isHappy = false;
}