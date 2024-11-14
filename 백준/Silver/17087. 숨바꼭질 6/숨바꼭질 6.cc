#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std; 

int n, s, result;
vector<int> v;

int divide(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;
    v.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] = abs(v[i] - s);
    }

    if (n == 1) result = v[0];
    else
    {
        result = divide(v[0], v[1]);
        for (int i = 2; i < n; i++)
        {
            result = divide(result, v[i]);
        }
    }

    cout << result;
    return 0;
}

int divide(int a, int b) 
{
    if (a % b == 0)
        return b;
    else
        return divide(b, a % b);
}