#include <iostream>
#include <algorithm>
#include <string>

using namespace std; 

string s, t;
int result;

bool check(int idx);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    getline(cin, s);
    getline(cin, t);
    for (int i = 0; i < s.size(); i++)
    {
        bool isAppear = check(i);
        if (isAppear)
        {
            result++;
            i += t.size() - 1;
        }
    }
    cout << result;
}

bool check(int idx)
{
    for (int i = 0; i < t.size(); i++)
    {
        if (idx + i >= s.size()) return false;
        if (s[idx + i] != t[i]) return false;
    }
    return true;
}