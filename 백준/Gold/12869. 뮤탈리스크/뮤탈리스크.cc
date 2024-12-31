#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, result = 1e9;
vector<int> v;
int dp[61][61][61];

void recursion(int a, int b, int c, int cnt);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(3, 0);
    for (int i = 0; i < n; i++) cin >> v[i];

    recursion(v[0], v[1], v[2], 0);
    cout << result;
    return 0;
}

void recursion(int a, int b, int c, int cnt)
{
    if (a < 0) a = 0;
    if (b < 0) b = 0;
    if (c < 0) c = 0;

    if (dp[a][b][c] != 0 && dp[a][b][c] <= cnt) return;
    dp[a][b][c] = cnt;

    if (a == 0 && b == 0 && c == 0)
    {
        result = min(result, cnt);
        return;
    }

    cnt++;
    if (n == 1) recursion(a - 9, 0, 0, cnt);

    if (n == 2)
    {
        recursion(a - 9, b - 3, 0, cnt);
        recursion(a - 3, b - 9, 0, cnt);
    }

    if (n == 3)
    {
        recursion(a - 9, b - 3, c - 1, cnt);
        recursion(a - 3, b - 9, c - 1, cnt);
        recursion(a - 1, b - 3, c - 9, cnt);
        recursion(a - 1, b - 9, c - 3, cnt);
        recursion(a - 9, b - 1, c - 3, cnt);
        recursion(a - 3, b - 1, c - 9, cnt);
    }
}
