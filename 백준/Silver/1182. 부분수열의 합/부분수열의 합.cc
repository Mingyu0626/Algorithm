#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std; 

int n, s, result;
vector<int> v;

int go(int idx, int sum);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) result += go(i, v[i]);
    
    cout << result;
    return 0;
}

int go(int idx, int sum)
{
    int ans = 0;
    if (sum == s) ans++;
    for (int i = idx + 1; i < n; i++) ans += go(i, sum + v[i]);
    return ans;
}