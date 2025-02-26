#include <iostream>

using namespace std;

int n, cnt = 1, sq = 10;
long long result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (sq == i)
        {
            sq *= 10;
            cnt++;
        }
        result += cnt;
    }
    cout << result;
    return 0;
}