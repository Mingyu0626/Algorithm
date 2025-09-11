#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n;
vector<vector<char>> v;

void recursion(int x, int y, int size);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, vector<char>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> v[i][j];

    recursion(0, 0, n);
    return 0;
}

void recursion(int x, int y, int size)
{

    char check = v[x][y];
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
        cout << check;
        return;
    }
    else
    {
        cout << "(";
        recursion(x, y, size / 2);
        recursion(x, y + size / 2, size / 2);
        recursion(x + size / 2, y, size / 2);
        recursion(x + size / 2, y + size / 2, size / 2);
        cout << ")";
    }
}
