#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
vector<vector<char>> v;
pair<int, int> result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> v[i][j];
        
    for (int i = 0; i < n; i++)
    {
        int cntRow = 0, cntCol = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == '.')
            {
                cntRow++;
                if (cntRow == 2) result.first++;
            }
            else cntRow = 0;

            if (v[j][i] == '.')
            {
                cntCol++;
                if (cntCol == 2) result.second++;
            }
            else cntCol = 0;
        }
    }
    cout << result.first << ' ' << result.second;
    return 0;
}