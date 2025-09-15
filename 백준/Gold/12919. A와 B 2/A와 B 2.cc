#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string s, t;
bool canChange;

void search(string cur);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s >> t;
    search(t);
    cout << canChange;
    return 0;
}

void search(string cur)
{
    if (s.length() == cur.length())
    {
        if (s == cur)
        {
            canChange = true;
        }
        return;
    }

    if (cur[cur.length() - 1] == 'A')
    {
        cur.pop_back();
        search(cur);
        cur.push_back('A');
    }

    if (cur[0] == 'B')
    {
        reverse(cur.begin(), cur.end());
        cur.pop_back();
        search(cur);
    }
}