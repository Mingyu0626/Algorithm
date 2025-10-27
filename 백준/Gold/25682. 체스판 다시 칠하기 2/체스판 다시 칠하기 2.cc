#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int n, m, k, result = 1e9;
Dim2Vec<char> v, vB, vW;
Dim2Vec<int> pSumB, pSumW;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    v.assign(n, vector<char>(m));
    vB.assign(n, vector<char>(m)), vW.assign(n, vector<char>(m));
    pSumB.assign(n + 1, vector<int>(m + 1, 0)); 
    pSumW.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> v[i][j];
            vW[i][j] = ((i + j) % 2 == 0) ? 'W' : 'B';
            vB[i][j] = ((i + j) % 2 == 0) ? 'B' : 'W';
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            pSumB[i + 1][j + 1] = (v[i][j] == vB[i][j]) ? 0 : 1;
            pSumW[i + 1][j + 1] = (v[i][j] == vW[i][j]) ? 0 : 1;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            pSumB[i][j] += pSumB[i - 1][j] + pSumB[i][j - 1] - pSumB[i - 1][j - 1];
            pSumW[i][j] += pSumW[i - 1][j] + pSumW[i][j - 1] - pSumW[i - 1][j - 1];
        }
    }

    for (int i = k; i <= n; ++i)
    {
        int curResult;
        for (int j = k; j <= m; ++j)
        {
            result = min({ result,
                pSumB[i][j] - pSumB[i - k][j] - pSumB[i][j - k] + pSumB[i - k][j - k],
                pSumW[i][j] - pSumW[i - k][j] - pSumW[i][j - k] + pSumW[i - k][j - k] });
        }
    }

    cout << result;
    return 0;
}