#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, result;
vector<int> set, single;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    set.assign(m, 0), single.assign(m, 0);
    for (int i = 0; i < m; i++) cin >> set[i] >> single[i];
    sort(set.begin(), set.end());
    sort(single.begin(), single.end());
    
    int quo = n / 6, mod = n % 6;
    result += min(single[0] * quo * 6, set[0] * quo);
    result += min(single[0] * mod, set[0]);
    cout << result;
}