#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string s;
unordered_set<string> us;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        string subString = "";
        for (int j = i; j < s.size(); j++)
        {
            subString += s[j];
            if (us.find(subString) == us.end())
            {
                us.insert(subString);
            }
        }
    }
    cout << us.size();
    return 0;
}