#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

struct info
{
    int x, y, dist, startX, startY;
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int bfs(const vector<string>& place);

vector<int> solution(vector<vector<string>> places) 
{
    vector<int> result;
    for (int i = 0; i < 5; ++i)
    {
        result.emplace_back(bfs(places[i]));
    }
    return result;
}

int bfs(const vector<string>& place)
{
    queue<info> q;
    Dim2Vec<bool> visited(5, vector<bool>(5, false));
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (place[i][j] == 'P')
            {
                q.push({i, j, 0, i, j});
                visited[i][j] = true;
            }
        }
    }
    
    while (!q.empty())
    {
        info cur = q.front();
        q.pop();
        
        
        for (int i = 0; i < 4; ++i)
        {
            int newX = cur.x + dx[i], newY = cur.y + dy[i];
            if (0 <= newX && newX < 5 && 0 <= newY && newY < 5)
            {
                if (place[newX][newY] == 'O' && !visited[newX][newY])
                {
                    if (cur.dist == 0)
                    {
                        q.push({newX, newY, 1, cur.startX, cur.startY});
                        visited[newX][newY] = true;
                    }
                }
                if (place[newX][newY] == 'P' && (newX != cur.startX || newY != cur.startY))
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}