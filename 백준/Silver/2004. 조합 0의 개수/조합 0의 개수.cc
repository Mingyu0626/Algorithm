#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
long long cur = 1, result;

long long divide(int num, int div);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if (n < 2 * m)
    {
        m = n - m;
    }

    cout << min(divide(n, 5) - divide(n - m, 5) - divide(m, 5),
        divide(n, 2) - divide(n - m, 2) - divide(m, 2));
    return 0;
}

long long divide(int num, int div)
{
    long long cnt = 0;
    for (long long i = div; 1 <= num / i; i *= div)
    {
        cnt += num / i;
    }
    return cnt;
}