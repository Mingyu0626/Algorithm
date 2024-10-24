#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

int n;
int l, r, m;
vector<int> v;
int result[3];
long long minPh = 3000000001;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            l = 0, r = n - 1;
            while (l <= r)
            {
                long long ph = v[i] + v[j];
                m = (r - l) / 2 + l;
                if (m == i || m == j)
                {
                    if (ph <= 0) l = m + 1;
                    else r = m - 1;
                }
                else
                {
                    ph += v[m];
                    if (abs(minPh) > abs(ph))
                    {
                        minPh = ph;
                        result[0] = i;
                        result[1] = j;
                        result[2] = m;
                    }
                    if (ph < 0) l = m + 1;
                    if (ph == 0) break;
                    if (ph > 0) r = m - 1;
                }
            }
        }
    }
    sort(result, result + 3);
    for (int i = 0; i < 3; i++) cout << v[result[i]] << ' ';
    return 0;
}