#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, curK;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> k;
    curK = n / 2;
    while (k <= curK)
    {
        int sortArea = n / curK;
        for (int i = 0; i < n; i += sortArea)
        {
            sort(v.begin() + i, v.begin() + i + sortArea);
        }
        curK /= 2;
    }
    for (int i = 0; i < n; i++) cout << v[i] << ' ';
    return 0;
}