#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, a;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        int tallerIdx = 0;
        for (int j = 1; j <= n; j++)
        {
            if (v[j] > i)
            {
                tallerIdx++;
                continue;
            }

            if (v[j] == 0)
            {
                if (tallerIdx == a)
                {
                    v[j] = i;
                    j = n;
                }
                else tallerIdx++;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << v[i] << ' ';
}