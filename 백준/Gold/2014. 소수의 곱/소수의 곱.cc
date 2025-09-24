#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int k, n;
vector<int> v;

void bfs();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> k >> n;
    v.assign(k, 0);
    for (int i = 0; i < k; ++i)
    {
        cin >> v[i];
    }

    bfs();
    return 0;
}

void bfs()
{
    priority_queue<long long> pq;
    for (int i = 0; i < k; ++i)
    {
        pq.push(-v[i]);
    }

    while (n--)
    {
        long long cur = -pq.top();
        pq.pop();

        if (n == 0)
        {
            cout << cur;
            return;
        }

        for (int i = 0; i < k; ++i)
        {
            long long next = cur * v[i];
            if (next < INT_MAX)
            {
                pq.push(-next);
            }

            if (cur % v[i] == 0)
            {
                break;
            }
        }
    }
}