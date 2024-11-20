#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dp[1000001];
vector<int> result;

void go(int curVal, int num, vector<int>& route);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> v;
    v.push_back(n);
    go(n, 0, v);

    cout << dp[1] << '\n';
    for (int i : result) cout << i << ' ';
    return 0;
}

void go(int curVal, int num, vector<int>& route)
{
    dp[curVal] = num;
    if (curVal == 1)
    {
        result = route;
        return;
    }
    if (curVal % 3 == 0)
    {
        if (dp[curVal / 3] == 0 || num + 1 < dp[curVal / 3])
        {
            route.push_back(curVal / 3);
            go(curVal / 3, num + 1, route);
            route.pop_back();
        }
    }
    if (curVal % 2 == 0)
    {
        if (dp[curVal / 2] == 0 || num + 1 < dp[curVal / 2])
        {
            route.push_back(curVal / 2);
            go(curVal / 2, num + 1, route);
            route.pop_back();
        }
    }
    if (dp[curVal - 1] == 0 || num + 1 < dp[curVal - 1])
    {
        route.push_back(curVal - 1);
        go(curVal - 1, num + 1, route);
        route.pop_back();
    }
}