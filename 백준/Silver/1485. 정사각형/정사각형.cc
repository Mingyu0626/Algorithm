#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;

int t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t > 0)
    {
        int x = 0, y = 0;
        vector<pii> a;
        unordered_map<double, int> um;
        for (int i = 0; i < 4; i++)
        {
            cin >> x >> y;
            for (int i = 0; i < a.size(); i++)
            {
                double length =
                    sqrt(pow(abs(a[i].first - x), 2) 
                        + pow(abs(a[i].second - y), 2));
                um[length]++;
            }
            a.push_back({ x, y });
        }
        if (um.size() == 2) cout << "1\n";
        else cout << "0\n";
        t--;
    }
    return 0;
}