#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, n, m, p;
priority_queue<int> pq;
queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> p;
            q.push({ i, p });
            pq.push(p);
        }
        
        int cnt = 1;
        while (!pq.empty())
        {
            if (q.front().second == pq.top())
            {
                if (q.front().first == m)
                {
                    cout << cnt << '\n';
                }
                pq.pop();
                cnt++;
            }
            else
            {
                q.push({ q.front() });
            }
            q.pop();
        }
    }
    return 0;
}