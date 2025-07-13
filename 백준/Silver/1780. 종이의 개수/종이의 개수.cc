#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n, result[3];
vector<vector<int>> v;

void recursion(int x, int y, int size);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> v[i][j];

    recursion(0, 0, n);
    for (int i = 0; i < 3; i++) cout << result[i] << "\n";
    return 0;
}

void recursion(int x, int y, int size)
{
    int a = size / 3, check = v[x][y];
    bool allSame = true;

    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (check != v[i][j])
            {
                allSame = false;
                i = x + size, j = y + size;
            }
        }
    }

    if (allSame)
    {
        result[check + 1]++;
        return;
    }
    else
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                recursion(x + a * i, y + a * j, a);       
    }
}
