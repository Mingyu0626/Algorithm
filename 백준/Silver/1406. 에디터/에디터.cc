#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s; 
    int n;
    cin >> s >> n;
    
    stack<char> s1, s2;
    for (int i = 0; i < s.length(); i++) s1.push(s[i]);
    
    char command;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == 'L')
        {
            if (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        else if (command == 'D')
        {
            if (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        else if (command == 'B')
        {
            if (!s1.empty())
            {
                s1.pop();
            }
        }
        else
        {
            char word;
            cin >> word;
            s1.push(word);
        }
    }

    string result;
    while (!s1.empty())
    {
        result += s1.top();
        s1.pop();
    }
    reverse(result.begin(), result.end());
    while (!s2.empty())
    {
        result += s2.top();
        s2.pop();
    }
    cout << result;
    return 0;
}