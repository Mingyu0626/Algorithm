#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std; 

int n, a, b, ms = 1e9, cd;
vector<int> v[51];
vector<int> score;

void bfs(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    score.assign(n + 1, 0);
    while (true)
    {
        cin >> a >> b;
        if (a == -1) break;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) bfs(i);
    
    ms = *min_element(score.begin() + 1, score.end());
    for (int i = 1; i <= n; i++)
        if (ms == score[i]) cd++;
    cout << ms << ' ' << cd << '\n';
    for (int i = 1; i <= n; i++)
        if (ms == score[i]) cout << i << ' ';
}

void bfs(int start)
{
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    int level = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            int cur = q.front().first;
            int curDist = q.front().second;
            q.pop();

            if (score[cur] == 0) score[cur] = curDist;
            else score[cur] = max(score[cur], curDist);

            for (int i = 0; i < v[cur].size(); i++)
            {
                int next = v[cur][i];
                if (!visited[next])
                {
                    q.push({ next, level + 1 });
                    visited[next] = true;
                }
            }
        }
        level++;
    }
}