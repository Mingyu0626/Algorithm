#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int route[100001];
vector<int> cntArr(100001, 1e9);
vector<int> result;

void bfs();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    pq.push({ 0, n });
    route[n] = -1;
    cntArr[n] = 0;
    bfs();
    reverse(result.begin(), result.end());
    result.push_back(k);
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    return 0;
}

void bfs()
{
    while (!pq.empty())
    {
        int t = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cur < 0 || 100000 < cur) continue;

        if (cur == k)
        {
            cout << t << "\n";
            while (route[cur] != -1)
            {
                result.push_back(route[cur]);
                cur = route[cur];
            }
            break;
        }

        if (cur * 2 <= 100000 && t + 1 < cntArr[cur * 2] && cur < k)
        {
            cntArr[cur * 2] = t + 1;
            route[cur * 2] = cur;
            pq.push({ t + 1, cur * 2 });
        }
        if (cur < 100000 && t + 1 < cntArr[cur + 1] && cur < k)
        {
            cntArr[cur + 1] = t + 1;
            route[cur + 1] = cur;
            pq.push({ t + 1, cur + 1 });
        }
        if (cur > 0 && t + 1 < cntArr[cur - 1])
        {
            cntArr[cur - 1] = t + 1;
            route[cur - 1] = cur;
            pq.push({ t + 1, cur - 1 });
        }
    }
}