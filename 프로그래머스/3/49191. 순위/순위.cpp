#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) 
{
    vector<vector<bool>> v(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < results.size(); ++i)
    {
        v[results[i][0]][results[i][1]] = true;
    }
    
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                if (v[j][i] && v[i][k])
                {
                    v[j][k] = true;
                }
            }
        }
    }
    
    int result = 0;
    for (int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (i != j && (v[i][j] || v[j][i]))
            {
                cnt++;
            }
        }
        if (cnt == n - 1)
        {
            result++;
        }
    }
    return result;
}