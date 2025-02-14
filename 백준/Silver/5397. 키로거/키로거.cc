#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (0 < t--)
    {
        string str;
        cin >> str;
        stack<char> cursorLeft, cursorRight;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '<')
            {
                if (!cursorLeft.empty())
                {
                    cursorRight.push(cursorLeft.top());
                    cursorLeft.pop();
                }
            }
            else if (str[i] == '>')
            {
                if (!cursorRight.empty())
                {
                    cursorLeft.push(cursorRight.top());
                    cursorRight.pop();
                }
            }
            else if (str[i] == '-')
            {
                if (!cursorLeft.empty())
                {
                    cursorLeft.pop();
                }
            }
            else
            {
                cursorLeft.push(str[i]);
            }
        }

        string result;
        while (!cursorLeft.empty())
        {
            result += cursorLeft.top();
            cursorLeft.pop();
        }
        reverse(result.begin(), result.end());
        while (!cursorRight.empty())
        {
            result += cursorRight.top();
            cursorRight.pop();
        }
        cout << result << '\n';
    }
    return 0;
}