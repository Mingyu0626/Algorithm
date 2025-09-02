#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int n, result;
vector<string> v;
unordered_set<string> us;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, "");
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    for (int i = n - 1; i >= 0; --i)
    {
        if (us.find(v[i]) == us.end())
        {
            string cur;
            for (int j = 0; j < v[i].size(); ++j)
            {
                cur += v[i][j];
                us.insert(cur);
            }
            result++;
        }
    }
    cout << result;
    return 0;
}