#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, w, l, result;
vector<int> v;
queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> w >> l;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];

    int curL = 0, idx = 0;
    while (idx < n)
    {
        result++;
        if (!q.empty() && result - q.front().second == w)
        {
            curL -= q.front().first;
            q.pop();
        }

        if (curL + v[idx] <= l)
        {
            q.push({ v[idx], result });
            curL += v[idx];
            idx++;
        }
    }
    result += w;
    cout << result;
    return 0;
}