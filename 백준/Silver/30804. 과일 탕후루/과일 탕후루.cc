#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, cur, kind = 1, result = 1;
vector<int> v;
unordered_map<int, int> um;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) 
    {
        cin >> v[i];
        if (um.find(v[i]) == um.end())
        {
            um.insert({ v[i], 0 });
        }
    }
    int l = 0, r = 1;
    um[v[l]]++;
    while (r < n)
    {
        if (um[v[r]] == 0)
        {
            kind++;
            if (2 < kind)
            {
                while (true)
                {
                    um[v[l]]--;
                    if (um[v[l]] == 0) break;
                    l++;
                }
                kind--;
                l++;
            }
        }
        um[v[r]]++;
        result = max(result, (r - l + 1));
        r++;
    }
    cout << result;
    return 0;
}