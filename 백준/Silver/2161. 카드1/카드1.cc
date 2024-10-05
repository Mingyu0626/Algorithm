#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

int n;
deque<int> dq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) dq.push_back(i);

    while (!dq.empty())
    {
        int cur = dq.front();
        dq.pop_front();
        cout << cur << ' ';
        if (dq.empty()) break;
        cur = dq.front();
        dq.pop_front();
        dq.push_back(cur);
    }
}