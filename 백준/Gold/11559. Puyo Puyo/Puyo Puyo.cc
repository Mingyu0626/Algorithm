#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int n, sum, combo = 0;
Dim2Vec<char> field;
pii dir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void fallDown();
bool tryExplode();
bool bfs(int i, int j, char target, Dim2Vec<bool>& visited);
bool isValid(const pii& coord);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    field.assign(12, vector<char>(6));
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            cin >> field[i][j];
        }
    }

    while (tryExplode())
    {
        fallDown();
        combo++;
    }
    cout << combo;
    return 0;
}

void fallDown()
{
    queue<pair<pii, char>> q;
    for (int i = 11; i >= 0; --i)
    {
        for (int j = 5; j >= 0; --j)
        {
            if (field[i][j] != '.')
            {
                q.push({ { i, j }, field[i][j] });
            }
        }
    }

    while (!q.empty())
    {
        pii cur = q.front().first;
        char curPuyo = q.front().second;
        q.pop();

        pii newCoord = { cur.first + 1, cur.second };
        if (isValid(newCoord) && field[newCoord.first][newCoord.second] == '.')
        {
            q.push({newCoord, curPuyo });
            field[cur.first][cur.second] = '.';
            field[newCoord.first][newCoord.second] = curPuyo;
        }
    }
}

bool tryExplode()
{
    Dim2Vec<bool> visited(12, vector<bool>(6, false));
    bool exploded = false;
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (!visited[i][j] && field[i][j] != '.')
            {
                if (bfs(i, j, field[i][j], visited))
                {
                    exploded = true;
                }
            }
        }
    }
    return exploded;
}

bool bfs(int i, int j, char target, Dim2Vec<bool>& visited)
{
    visited[i][j] = true;
    vector<pii> explodedPuyo;
    queue<pii> q;
    q.push({ i, j });
    while (!q.empty())
    {
        pii cur = q.front();
        explodedPuyo.emplace_back(cur);
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            pii newCoord = { cur.first + dir[i].first, cur.second + dir[i].second };
            if (isValid(newCoord) && !visited[newCoord.first][newCoord.second]
                && field[newCoord.first][newCoord.second] == target)
            {
                q.push(newCoord);
                visited[newCoord.first][newCoord.second] = true;
            }
        }
    }

    if (4 <= explodedPuyo.size())
    {
        for (int i = 0; i < explodedPuyo.size(); ++i)
        {
            field[explodedPuyo[i].first][explodedPuyo[i].second] = '.';
        }
        return true;
    }
    return false;
}

bool isValid(const pii& coord)
{
    return 0 <= coord.first && coord.first < 12 && 0 <= coord.second && coord.second < 6;
}