#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
template<typename T>
using Dim2Vec = vector<vector<T>>;

int n;
double result;
vector<double> p(4, 0);
Dim2Vec<bool> visited(29, vector<bool>(29, false));

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void dfs(int moveCnt, double curProb, int y, int x);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> p[0] >> p[1] >> p[2] >> p[3];
    dfs(0, 1.0, 14, 14);

    cout.precision(10);
    cout << result;
    return 0;
}

void dfs(int moveCnt, double curProb, int y, int x)
{
    if (curProb == 0)
    {
        return;
    }

    if (moveCnt == n)
    {
        result += curProb;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int newY = y + dy[i];
        int newX = x + dx[i];
        if (visited[newY][newX])
        {
            continue;
        }

        double newProb = curProb * (p[i] / 100.0);
        visited[y][x] = true;
        dfs(moveCnt + 1, newProb, newY, newX);
        visited[y][x] = false;
    }
}