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
    v.assign(n, 0), result.assign(n, -1);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty())
        {
            if (v[i] < s.top())
            {
                result[i] = s.top();
                break;
            }
            else s.pop();
        }
        s.push(v[i]);
    }

    for (int i = 0; i < n; i++) cout << result[i] << ' ';
    return 0;
}