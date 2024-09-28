#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

int n, l, r, result;
string s;
unordered_map<char, int> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;

    while (r < s.size())
    {
        if (um.find(s[r]) != um.end())
        {
            um[s[r]]++;
            r++;
        }
        else
        {
            if (um.size() < n)
            {
                um.insert({s[r], 1});
                r++;
            }
            else
            {
                um[s[l]]--;
                if (um[s[l]] == 0) um.erase(s[l]);
                l++;
            }
        }
        result = max(result, r - l);
    }
    cout << result;
}