#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int m, n;
vector<bool> v(1000001, false);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;
    v[1] = true;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (!v[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                v[j] = true;
            }
        }
    }

    for (int i = m; i <= n; i++)
        if (!v[i]) cout << i << '\n';
}