#include <iostream>
#include <string>
#include <vector>

using namespace std;

int result;
vector<bool> visited;

void dfs(int num, const int n, const vector<vector<int>>& computers);

int solution(int n, vector<vector<int>> computers) 
{
    visited.assign(n, false);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(i, n, computers);
            result++;
        }
    }
    return result;
}

void dfs(int num, const int n, const vector<vector<int>>& computers)
{
    visited[num] = true;
    for (int i = 0; i < n; ++i)
    {
        if (num != i && computers[num][i] == 1 && !visited[i])
        {
            dfs(i, n, computers);
        }
    }
}