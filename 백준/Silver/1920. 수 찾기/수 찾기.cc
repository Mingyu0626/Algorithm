#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

int n, m, a;
unordered_map<int, int> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        um[a]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        if (um.find(a) == um.end())
        {
            cout << "0\n";
        }
        else
        {
            cout << "1\n";
        }
    }
    return 0;
}