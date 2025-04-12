#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
int n, cur;
long long result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        while (!s.empty())
        {
            int top = s.top();
            if (top <= cur)
            {
                s.pop();
            }
            else
            {
                break;
            }
        }
        result += s.size();
        s.push(cur);
    }
    cout << result;
    return 0;
}