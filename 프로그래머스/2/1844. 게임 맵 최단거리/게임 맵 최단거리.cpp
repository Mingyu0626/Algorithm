#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string_view>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <ctime>
#include <bitset>
#include <cstdio>
#include <limits>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>

using namespace std;

int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(const vector<vector<int>>& maps);

int solution(vector<vector<int>> maps)
{
    n = maps.size(), m = maps[0].size();
    return bfs(maps);
}

int bfs(const vector<vector<int>>& maps)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[0][0] = true;
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    int level = 1;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            int curX = q.front().first, curY = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int newX = curX + dx[i], newY = curY + dy[i];
                if (0 <= newX && newX < n && 0 <= newY && newY < m &&
                !visited[newX][newY] && maps[newX][newY] == 1)
                {
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                    if (newX + 1 == n && newY + 1 == m)
                    {
                        return level + 1;
                    }
                }
            }
        }
        level++;
    }
    return -1;
}