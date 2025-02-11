#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, treeCount;

struct fieldInfo
{
    vector<int> aliveTrees;
    int nutrition = 5;
    int deathTreeNutrition = 0;
    int breedTreeCount = 0;
    int s2d2 = 0;
};
using Dim2FieldInfo = vector<vector<fieldInfo>>;


void spring(Dim2FieldInfo& f)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            vector<int> growthSucceedTrees;
            sort(f[i][j].aliveTrees.begin(), f[i][j].aliveTrees.end());
            for (auto& a : f[i][j].aliveTrees)
            {
                int curTreeAge = a;
                if (curTreeAge <= f[i][j].nutrition)
                {
                    growthSucceedTrees.emplace_back(curTreeAge + 1);
                    f[i][j].nutrition -= curTreeAge;
                    if ((curTreeAge + 1) % 5 == 0)
                    {
                        f[i][j].breedTreeCount++;
                    }
                }
                else
                {
                    f[i][j].deathTreeNutrition += curTreeAge / 2;
                    treeCount--;
                }
            }
            f[i][j].aliveTrees.clear();
            for (auto& a : growthSucceedTrees)
            {
                f[i][j].aliveTrees.push_back(a);
            }
        }
    }
}

void summer(Dim2FieldInfo& f)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j].nutrition += f[i][j].deathTreeNutrition;
            f[i][j].deathTreeNutrition = 0;
        }
    }
}

void autumn(Dim2FieldInfo& f)
{
    int dr[8] = { 1, 1, 1, -1, -1, -1, 0, 0 };
    int dc[8] = { 0, -1, 1, 0, -1, 1, -1, 1 };

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (0 < f[i][j].breedTreeCount)
            {
                for (int k = 0; k < 8; k++)
                {
                    int newR = i + dr[k];
                    int newC = j + dc[k];
                    if (1 <= newR && newR <= n && 1 <= newC && newC <= n)
                    {
                        int cnt = f[i][j].breedTreeCount;
                        while (0 < cnt--)
                        {
                            f[newR][newC].aliveTrees.push_back(1);
                            treeCount++;
                        }
                    }
                }
                f[i][j].breedTreeCount = 0;
            }
        }
    }
}

void winter(Dim2FieldInfo& f)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j].nutrition += f[i][j].s2d2;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    treeCount = m;
    Dim2FieldInfo field(n + 1, vector<fieldInfo>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> field[i][j].s2d2;
        
    int x, y, z;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        field[x][y].aliveTrees.push_back(z);
    }

    while (0 < k--)
    {
        spring(field);
        summer(field);
        autumn(field);
        winter(field);
    }

    cout << treeCount;
    return 0;
}