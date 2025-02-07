#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using Dim3Bool = vector<vector<vector<bool>>>;

int k, w, h;
const int dh[4] = { 0, 0, 1, -1 }, dw[4] = { 1, -1, 0, 0 };
const int horseH[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
const int horseW[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

int bfs(const vector<vector<int>>& v, Dim3Bool& visited);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> k >> w >> h;

    vector<vector<int>> v(h, vector<int>(w));
    Dim3Bool visited(h, vector<vector<bool>>(w, vector<bool>(k + 1, false)));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) cin >> v[i][j];
    
    cout << bfs(v, visited);
    return 0;
}

int bfs(const vector<vector<int>>& v, Dim3Bool& visited)
{
    struct pointInfo{ int h, w, usedJump; };
    queue<pointInfo> q;
    q.push({ 0, 0, 0 });
    visited[0][0][0] = true;
    int result = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++)
        {
            pointInfo cur = q.front();
            q.pop();
            if (cur.h == h - 1 && cur.w == w - 1) return result;

            for (int j = 0; j < 8; j++)
            {
                int newH = cur.h + horseH[j], newW = cur.w + horseW[j];
                if (0 <= newH && newH < h && 0 <= newW && newW < w &&
                    v[newH][newW] == 0 && cur.usedJump < k &&
                    !visited[newH][newW][cur.usedJump + 1])
                {
                    visited[newH][newW][cur.usedJump + 1] = true;
                    q.push({ newH, newW, cur.usedJump + 1 });
                }
            }

            for (int j = 0; j < 4; j++)
            {
                int newH = cur.h + dh[j], newW = cur.w + dw[j];
                if (0 <= newH && newH < h && 0 <= newW && newW < w &&
                    v[newH][newW] == 0 && !visited[newH][newW][cur.usedJump])
                {
                    visited[newH][newW][cur.usedJump] = true;
                    q.push({ newH, newW, cur.usedJump});
                }
            }
        }
        result++;
    }
    return -1;
}