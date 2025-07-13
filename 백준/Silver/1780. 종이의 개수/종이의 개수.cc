#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
template<typename T>
using Dim2Vec = vector<vector<T>>;

int n, result[3];
Dim2Vec<int> v;

void recursion(int x, int y, int paperSize);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    recursion(0, 0, n);
    for (int i = 0; i < 3; i++)
    {
        cout << result[i] << '\n';
    }
    return 0;
}

void recursion(int x, int y, int paperSize)
{
    int newPaperSize = paperSize / 3, check = v[x][y];
    bool isSame = true;

    for (int i = x; i < x + paperSize; i++)
    {
        for (int j = y; j < y + paperSize; j++)
        {
            if (check != v[i][j])
            {
                isSame = false;
            }
        }
    }

    if (isSame)
    {
        result[check + 1]++;
        return;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                recursion(x + newPaperSize * i, y + newPaperSize * j, newPaperSize);
            }
        }
    }
}