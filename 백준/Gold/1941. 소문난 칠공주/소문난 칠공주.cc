#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int result;
vector<vector<char>> v(5, vector<char>(5));
vector<vector<bool>> isPicked(5, vector<bool>(5, false));
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void pickPrincess(int count, int dasomCount, int index);
void bfs();


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> v[i][j];
        }
    }
    pickPrincess(0, 0, 0);
    cout << result;
    return 0;
}

void pickPrincess(int count, int dasomCount, int index)
{
    if (count == 7 && 4 <= dasomCount)
    {
        bfs();
        return;
    }

    if (4 <= count - dasomCount)
    {
        return;
    }
    
    for (int i = index; i < 25; i++)
    {
        int x = i / 5, y = i % 5;

        isPicked[x][y] = true;
        pickPrincess(count + 1, dasomCount + (v[x][y] == 'S' ? 1 : 0), i + 1);
        isPicked[x][y] = false;
    }
}

void bfs()
{
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (isPicked[i][j])
            {
                q.push({ i, j });
                visited[i][j] = true;
                i = 5, j = 5;
            }
        }
    }
    int princessCount = 1;
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i];
            int newY = curY + dy[i];
            if (newX < 0 || 5 <= newX || newY < 0 || 5 <= newY)
            {
                continue;
            }
            if (!visited[newX][newY] && isPicked[newX][newY])
            {
                q.push({ newX, newY });
                visited[newX][newY] = true;
                princessCount++;
            }
        }
    }

    if (princessCount == 7)
    {
        result++;
    }
}