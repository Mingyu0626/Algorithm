#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, result;
vector<vector<char>> v;
bool a[27];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void search(int x, int y, int cnt);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> r >> c;
    v.assign(r, vector<char>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> v[i][j];
        }
    }
    a[v[0][0] - 'A'] = true;
    search(0, 0, 1);
    cout << result;
    return 0;
}

void search(int x, int y, int cnt)
{
    result = max(result, cnt);
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX < 0 || r <= newX || newY < 0 || c <= newY) continue;

        int next = v[newX][newY] - 'A';
        if (!a[next])
        {
            a[next] = true;
            search(newX, newY, cnt + 1);
            a[next] = false;
        }
    }
}