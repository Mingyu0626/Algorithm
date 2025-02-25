#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int n;
vector<int> v;
deque<int> dq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++)
    {
        int skill = v[n - i];
        if (skill == 1)
        {
            dq.emplace_front(i);
        }
        else if (skill == 2)
        {
            int front = dq.front();
            dq.pop_front();
            dq.emplace_front(i);
            dq.emplace_front(front);
        }
        else
        {
            dq.emplace_back(i);
        }
    }

    for (int i = 0; i < dq.size(); i++) cout << dq[i] << ' ';
    return 0;
}