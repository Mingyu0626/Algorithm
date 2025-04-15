#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int n;
string cur;
unordered_set<string> us;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        sort(cur.begin(), cur.end());
        if (us.find(cur) == us.end())
        {
            us.insert(cur);
        }
    }
    cout << us.size();
    return 0;
}