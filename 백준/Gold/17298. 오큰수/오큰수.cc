#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<int> v, result;
stack<int> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, 0), result.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    result[n - 1] = -1;
    s.push(v[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty())
        {
            if (v[i] < s.top())
            {
                result[i] = s.top();
                s.push(v[i]);
                break;
            }
            else s.pop();
        }
        if (s.empty())
        {
            result[i] = -1;
            s.push(v[i]);
        }
    }

    for (int i = 0; i < n; i++) cout << result[i] << ' ';
    return 0;
}