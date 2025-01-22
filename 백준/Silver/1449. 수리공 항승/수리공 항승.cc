#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l, result;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> l;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int s = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] - s >= l)
        {
            result++;
            s = v[i];
        }
    }
    cout << result + 1;
    return 0;
}


