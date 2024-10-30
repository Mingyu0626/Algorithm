#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

string a, result;
stack<pair<char, int>> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a;
    for (int i = 0; i < a.size(); i++)
    {
        if ('A' <= a[i] && a[i] <= 'Z')
        {
            result += a[i];
        }
        else if (a[i] == '(')
        {
            s.push({ '(', -1 });
        }
        else if (a[i] == ')')
        {
            while (!s.empty())
            {
                int cur = s.top().first;
                s.pop();
                if (cur == '(') break;
                else result += cur;
            }
        }
        else if (a[i] == '-' || a[i] == '+' || a[i] == '*' || a[i] == '/')
        {
            int priority = 1;
            if (a[i] == '*' || a[i] == '/') priority = 2;

            while (!s.empty())
            {
                int cur = s.top().first;
                int p = s.top().second;
                if (priority <= p)
                {
                    s.pop();
                    result += cur;
                }
                else break;
            }
            s.push({ a[i], priority });
        }
    }
    while (!s.empty())
    {
        int cur = s.top().first;
        s.pop();
        result += cur;
    }

    cout << result;
    return 0;
}