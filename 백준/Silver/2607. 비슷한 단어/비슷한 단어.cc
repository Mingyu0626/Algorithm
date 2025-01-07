#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n, result;
string target, s;
unordered_map<char, int> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> target;
    for (int i = 0; i < target.length(); i++) um[target[i]]++;
    
    for (int i = 1; i < n; i++)
    {
        cin >> s;
        if (s.length() < target.length() - 1 || target.length() + 1 < s.length()) continue;
        unordered_map<char, int> um2;
        int distance = 0;
        if (s.length() == target.length() - 1) distance++;
        for (int j = 0; j < s.length(); j++)
        {
            um2[s[j]]++;
            if (um.find(s[j]) != um.end() && um2[s[j]] <= um[s[j]]) continue;
            distance++;
        }
        if (distance <= 1) result++;
    }
    cout << result;
    return 0;
}