#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
vector<int> v(14, 0);

void combination(int idx, vector<int>& result);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin >> k && k != 0)
    {
        v.clear();
        for (int i = 1; i <= k; ++i)
        {
            cin >> v[i];
        }
        vector<int> result;
        combination(0, result);
        cout << '\n';
    }
    return 0;
}

void combination(int idx, vector<int>& result)
{
    if (result.size() == 6)
    {
        for (const auto& a : result)
        {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = idx + 1; i <= k; ++i)
    {
        result.emplace_back(v[i]);
        combination(i, result);
        result.pop_back();
    }
}