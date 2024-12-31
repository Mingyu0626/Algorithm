#include <iostream>
#include <string>
#include <stack>

using namespace std;

int n, result;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        stack<char> st;
        st.push(s[0]);
        for (int j = 1; j < s.size(); j++)
        {
            if (!st.empty() && st.top() == s[j]) st.pop();
            else st.push(s[j]);
        }
        if (st.empty()) result++;
    }
    cout << result;
    return 0;
}