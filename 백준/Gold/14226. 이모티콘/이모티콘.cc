#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int s;
vector<vector<bool>> visited;

void bfs(int start);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    visited.assign(s + 1, vector<bool>(s + 1, false));
    bfs(1);
    return 0;
}

void bfs(int start)
{
    queue<pair<int, int>> q;
    visited[start][0] = 0;
    q.push({start, 0});

    int level = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            int curEmoticon = q.front().first;
            int curClipboard = q.front().second;
            q.pop();

            if (curEmoticon == s)
            {
                cout << level;
                return;
            }
            if (curEmoticon <= s && !visited[curEmoticon][curEmoticon])
            {
                q.push({ curEmoticon, curEmoticon });
                visited[curEmoticon][curEmoticon] = true;
            }
            if (curEmoticon + curClipboard <= s
                && !visited[curEmoticon + curClipboard][curClipboard])
            {
                q.push({ curEmoticon + curClipboard, curClipboard });
                visited[curEmoticon + curClipboard][curClipboard] = true;
            }
            if (0 < curEmoticon && !visited[curEmoticon - 1][curClipboard])
            {
                q.push({ curEmoticon - 1, curClipboard });
                visited[curEmoticon - 1][curClipboard] = true;
            }
        }
        level++;
    }
}