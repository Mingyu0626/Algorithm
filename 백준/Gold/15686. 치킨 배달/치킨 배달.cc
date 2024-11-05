#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, result = 1e9;
vector<pair<int, int>> home, chicken, searchChicken;
vector<vector<int>> v;
bool chickenVisited[14];

void combination(int cnt);
void calc();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 1) home.push_back({ i, j });
            if (v[i][j] == 2) chicken.push_back({ i, j });
        }
    }
    combination(0);
    cout << result;
    return 0;
}

void combination(int cnt)
{
    if (searchChicken.size() == m)
    {
        calc();
        return;
    }
    for (int i = cnt; i < chicken.size(); i++)
    {
        searchChicken.push_back(chicken[i]);
        combination(i + 1);
        searchChicken.pop_back();
    }
}

void calc()
{
    int curChickenDist = 0;
    for (int i = 0; i < home.size(); i++)
    {
        int curHomeChickenDist = 1e9;
        for (int j = 0; j < searchChicken.size(); j++)
        {
            curHomeChickenDist = min(curHomeChickenDist,
                abs(home[i].first - searchChicken[j].first)
                + abs(home[i].second - searchChicken[j].second));
        }
        curChickenDist += curHomeChickenDist;
    }
    result = min(result, curChickenDist);
}