#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

string str, b, result;
stack<char> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> str >> b;
    for (int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
        if (str[i] == b[b.size() - 1] && s.size() >= b.size())
        {
            string strComp;
            for (int j = 0; j < b.size(); j++)
            {
                strComp += s.top();
                s.pop();
            }
            reverse(strComp.begin(), strComp.end());
            if (strComp != b)
            {
                for (int j = 0; j < strComp.size(); j++)
                {
                    s.push(strComp[j]);
                }
            }
        }
    }
    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }
    reverse(result.begin(), result.end());
    if (result.size() == 0) cout << "FRULA";
    else cout << result;
    return 0;
}