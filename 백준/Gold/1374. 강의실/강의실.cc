#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using Pii = pair<int, int>;

int n, num, s, e;
vector<Pii> v;
priority_queue<int> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num >> s >> e;
        v.emplace_back(s, e);
    }
    sort(v.begin(), v.end(), [](const Pii& a, const Pii& b)
        { return a.second > b.second; });

    for (int i = 0; i < n; i++)
    {
        if (!pq.empty())
        {
            int latestStart = pq.top();
            if (v[i].second <= latestStart)
            {
                pq.pop();
            }
        }
        pq.push(v[i].first);
    }
    cout << pq.size();
    return 0;
}