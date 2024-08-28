#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, minEndTime, result;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, { 0, 0 });
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    pq.push(v[0].second);
    for (int i = 1; i < n; i++)
    {
        if (pq.top() <= v[i].first) pq.pop();
        pq.push(v[i].second);
    }

    cout << pq.size();
    return 0;
}