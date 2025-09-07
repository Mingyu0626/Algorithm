#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int n, result;
string s;
unordered_map<string, int> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        um[s] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        if (i < um[s])
        {
            result++;
            for (const auto& a : um)
            {
                if (a.second < um[s])
                {
                    um[a.first]++;
                }
            }
        }
    }
    cout << result;
    return 0;
}