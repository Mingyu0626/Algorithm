#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string str;
    while (true)
    {
        getline(cin, str);
        if (str.compare(".") == 0) break;
        stack<char> s;
        unordered_map<char, int> um;
        bool isBalanced = true;
        
        for (int i = 0; i < str.size(); i++)
        {
            char cur = str.at(i);
            if (cur == '(' || cur == '[')
            {
                s.push(cur);
                um[cur]++;
            }

            if (cur == ')' || cur == ']')
            {
                um[cur]++;
                if (s.size() == 0)
                {
                    isBalanced = false;
                    break;
                }
                char lastLeft = s.top();
                s.pop();

                if (!(cur == ')' && lastLeft == '(' ||
                    cur == ']' && lastLeft == '['))
                {
                    isBalanced = false;
                    break;
                }
            }
        }
        if (um['('] != um[')'] || um['['] != um[']']) isBalanced = false;
        if (isBalanced) cout << "yes\n";
        else cout << "no\n";
    }
}