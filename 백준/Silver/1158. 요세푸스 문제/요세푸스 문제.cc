#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, cnt, curIdx = -1;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    v.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }

    cout << '<';
    while (cnt < n)
    {
        for (int i = 0; i < k; i++)
        {
            curIdx = (curIdx + 1) % n;
            if (v[curIdx] == -1)
            {
                i -= 1;
            }
        }
        cout << v[curIdx];
        if (cnt + 1 < n)
        {
            cout << ", ";
        }
        v[curIdx] = -1;
        cnt++;
    }
    cout << '>';
    return 0;
}