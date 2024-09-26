#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int a, b;
map<int, int> mx, my;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 3; i++)
    {
        cin >> a >> b;
        mx[a]++;
        my[b]++;
    }
    for (const pair<int, int>& p : mx)
        if (p.second == 1) cout << p.first << ' ';

    for (const pair<int, int>& p : my)
        if (p.second == 1) cout << p.first;
    
    return 0;
}