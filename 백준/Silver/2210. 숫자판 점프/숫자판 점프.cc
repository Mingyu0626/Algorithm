#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std; 

int result;
unordered_set<string> us;
vector<vector<char>> v(5, vector<char>(5));
vector<vector<bool>> visited(5, vector<bool>(5));
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y, string s);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) cin >> v[i][j];
        
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            dfs(i, j, "");
        }
    }

    cout << result;
    return 0;
}

void dfs(int x, int y, string s)
{
    if (s.size() == 6)
    {
        if (us.find(s) == us.end())
        {
            result++;
            us.insert(s);
        }
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX < 0 || 5 <= newX || newY < 0 || 5 <= newY) continue;
            dfs(newX, newY, s + v[newX][newY]);
        }
    }
}