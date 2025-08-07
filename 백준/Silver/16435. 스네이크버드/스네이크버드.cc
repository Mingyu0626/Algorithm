#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> l;
    v.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i] <= l)
        {
            l++;
        }
    }
    cout << l;
    return 0;
}