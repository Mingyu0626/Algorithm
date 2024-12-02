#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int r, c, result;
vector<vector<char>> v;
map<char, bool> m;
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
            if (m.find(v[i][j]) == m.end())
            {
                m.insert({ v[i][j], false });
            }
        }
    }
    m[v[0][0]] = true;
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

        char next = v[newX][newY];
        if (!m[next])
        {
            m[next] = true;
            search(newX, newY, cnt + 1);
            m[next] = false;
        }
    }
}