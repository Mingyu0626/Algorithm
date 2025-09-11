#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int n;
Dim2Vec<char> v;

void divide(int x, int y, int dist);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, vector<char>(n, ' '));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> v[i][j];
        }
    }
    divide(0, 0, n);
    return 0;
}

void divide(int x, int y, int dist)
{
    char target = v[x][y];
    for (int i = x; i < x + dist; ++i)
    {
        for (int j = y; j < y + dist; ++j)
        {
            if (target != v[i][j])
            {
                cout << '(';
                divide(x, y, dist / 2);
                divide(x, y + dist / 2, dist / 2);
                divide(x + dist / 2, y, dist / 2);
                divide(x + dist / 2, y + dist / 2, dist / 2);
                cout << ')';
                return;
            }
        }
    }
    cout << target;
}