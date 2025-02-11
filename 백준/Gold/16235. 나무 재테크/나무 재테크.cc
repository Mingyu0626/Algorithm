#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k, treeCount;

struct fieldInfo
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int nutrition = 5;
    int deathTreeNutrition = 0;
    int breedTreeCount = 0;
    int s2d2 = 0;
};
using Dim2FieldInfo = vector<vector<fieldInfo>>;


void springGrowthTree(Dim2FieldInfo& f)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            vector<int> growthSucceedTrees;
            while (!f[i][j].pq.empty())
            {
                int curTreeAge = f[i][j].pq.top();
                f[i][j].pq.pop();
                if (curTreeAge <= f[i][j].nutrition)
                {
                    growthSucceedTrees.emplace_back(curTreeAge + 1);
                    f[i][j].nutrition -= curTreeAge;
                }
                else
                {
                    f[i][j].deathTreeNutrition += curTreeAge / 2;
                    treeCount--;
                }
            }
            for (auto& a : growthSucceedTrees)
            {
                f[i][j].pq.push(a);
                if (a % 5 == 0)
                {
                    f[i][j].breedTreeCount++;
                }
            }
        }
    }
}

void summerTurnTreeIntoNutrition(Dim2FieldInfo& f)
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

void autumnBreedTree(Dim2FieldInfo& f)
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
                            f[newR][newC].pq.push(1);
                            treeCount++;
                        }
                    }
                }
                f[i][j].breedTreeCount = 0;
            }
        }
    }
}

void winterAddNutrition(Dim2FieldInfo& f)
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
        field[x][y].pq.push(z);
    }

    while (0 < k--)
    {
        springGrowthTree(field);
        summerTurnTreeIntoNutrition(field);
        autumnBreedTree(field);
        winterAddNutrition(field);
    }

    cout << treeCount;
    return 0;
}