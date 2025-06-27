#include <iostream>
#include <vector>
#include <queue>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;
using pii = pair<int, int>;

int n;
Dim2Vec<char> v;
queue<pii> cacheQueue;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void SetupObstacle(int count);
bool tryFindStudent();
bool isValid(int x, int y);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'T')
            {
                cacheQueue.push({ i, j });
            }
        }
    }

    SetupObstacle(0);
    cout << "NO";
    return 0;
}

void SetupObstacle(int count)
{
    if (count == 3)
    {
        if (tryFindStudent())
        {
            return;
        }
        else
        {
            cout << "YES";
            exit(0);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == 'X')
                {
                    v[i][j] = 'O';
                    SetupObstacle(count + 1);
                    v[i][j] = 'X';
                }
            }
        }
    }
}

bool tryFindStudent()
{
    queue<pii> q = cacheQueue;
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = curX, newY = curY;
            while (isValid(newX, newY))
            {
                if (v[newX][newY] == 'S')
                {
                    return true;
                }
                newX += dx[i], newY += dy[i];
            }
        }
    }
    return false;
}

bool isValid(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < n && v[x][y] != 'O';
}