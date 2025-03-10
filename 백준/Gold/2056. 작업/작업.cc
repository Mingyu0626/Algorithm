#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
vector<vector<int>> priorityTasks;
vector<int> dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    priorityTasks.assign(n + 1, vector<int>()), dp.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> dp[i] >> m;
        priorityTasks[i].assign(m, 0);

        for (int j = 0; j < m; j++)
        {
            cin >> priorityTasks[i][j];
        }
    }

    int maxTime;
    for (int i = 1; i <= n; i++)
    {
        if (0 < priorityTasks[i].size())
        {
            maxTime = 0;
            for (int j = 0; j < priorityTasks[i].size(); j++)
            {
                maxTime = max(maxTime, dp[priorityTasks[i][j]]);
            }
            dp[i] += maxTime;
        }
    }

    cout << *max_element(dp.begin(), dp.end());
    return 0;
}