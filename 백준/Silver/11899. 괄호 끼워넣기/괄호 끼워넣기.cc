#include <iostream>
#include <string>
#include <stack>

using namespace std;

int result;
string str;
stack<char> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> str;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.empty())
            {
                result++;
            }
            else
            {
                s.pop();
            }
        }
    }
    result += s.size();
    cout << result;
    return 0;
}