#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>

using namespace std;

int n, curN = 1, idx;
bool tsukureru = true;
vector<int> v;
stack<int> s;
string result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];

    while (idx < n)
    {
        if (curN <= v[idx])
        {
            while (curN <= v[idx])
            {
                s.push(curN);
                result += '+';
                curN++;
            }
            s.pop();
            result += '-';
        }
        else
        {
            if (s.top() != v[idx])
            {
                tsukureru = false;
                break;
            }
            else
            {
                s.pop();
                result += '-';
            }
        }
        idx++;
    }

    if (!tsukureru) cout << "NO";
    else
    {
        for (int i = 0; i < result.size(); i++) 
            cout << result[i] << '\n';
    }    
    return 0;
}