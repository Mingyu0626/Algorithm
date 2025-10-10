#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
using Dim2Vec = vector<vector<T>>;

int solution(vector<vector<int>> board, vector<vector<int>> skill) 
{
    int n = board.size(), m = board[0].size();
    Dim2Vec<int> diff(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 0; i < skill.size(); ++i)
    {
        int type = skill[i][0], r1 = skill[i][1], c1 = skill[i][2], r2 = skill[i][3], c2 = skill[i][4];
        int degree = skill[i][5];
        if (type == 1)
        {
            degree *= -1;
        }
        diff[r1][c1] += degree;
        diff[r2 + 1][c1] -= degree;
        diff[r1][c2 + 1] -= degree;
        diff[r2 + 1][c2 + 1] += degree;
    }
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            diff[i][j] += diff[i][j - 1];
        }
    }
    for (int j = 0; j < m; ++j)
    {
        for (int i = 1; i < n; ++i)
        {
            diff[i][j] += diff[i - 1][j];
        }
    }
    
    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (0 < board[i][j] + diff[i][j])
            {
                result++;
            }
        }
    }
    return result;
}