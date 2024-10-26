#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 

long long t, n, maxPrice, result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t > 0)
    {
        maxPrice = 0, result = 0;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        
        for (int i = n - 1; i >= 0; i--)
        {
            if (maxPrice < v[i]) maxPrice = v[i];
            if (maxPrice > v[i]) result += (maxPrice - v[i]);
        }
        cout << result << '\n';
        t--;
    }
    return 0;
}