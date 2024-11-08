#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, result;
vector<vector<int>> dice;
int topBottom[6] = { 5, 3, 4, 1, 2, 0 };
// (0, 5), (1, 3), (2, 4)


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    dice.assign(n, vector<int>(6));
    for (int i = 0; i < n; i++)
    {
        cin >> dice[i][0] >> dice[i][1] >> dice[i][2]
            >> dice[i][3] >> dice[i][4] >> dice[i][5];
    }

    for (int i = 0; i < 6; i++)
    {
        int top = dice[0][i];
        int bottom = dice[0][topBottom[i]];
        int cur = 0;
        if (top != 6 && bottom != 6) cur = 6;
        else if (top != 5 && bottom != 5) cur = 5;
        else cur = 4;

        for (int j = 1; j < n; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                if (dice[j][k] == top)
                {
                    bottom = dice[j][k];
                    top = dice[j][topBottom[k]];
                    break;
                }
            }
            if (top != 6 && bottom != 6) cur += 6;
            else if (top != 5 && bottom != 5) cur += 5;
            else cur += 4;
        }
        result = max(result, cur);
    }
    cout << result;
    return 0;
}