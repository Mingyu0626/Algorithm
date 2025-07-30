#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct line
{
    int s, e;
    line(int s, int e)
    {
        this->s = s;
        this->e = e;
    }
};

int n, s, e, result;
vector<line> v;
priority_queue<int> pq;

bool compare(const line& a, const line& b)
{
    if (a.s == b.s)
    {
        return a.e < b.e;
    }
    return a.s < b.s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.reserve(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        v.emplace_back(s, e);
    }
    sort(v.begin(), v.end(), compare);
    pq.push(-v[0].e);
    for (int i = 1; i < n; i++)
    {
        int cur = -pq.top();
        if (cur <= v[i].s)
        {
            pq.pop();
        }
        pq.push(-v[i].e);
    }
    cout << pq.size();
    return 0;
}