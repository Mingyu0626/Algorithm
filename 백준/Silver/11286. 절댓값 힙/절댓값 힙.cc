#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int n, num, result;
vector<int> v;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top().second << '\n';
                pq.pop();
            }
            else cout << 0 << '\n';
        }
        else
        {
            pq.push({ abs(num), num });
        }
    }
    return 0;
}