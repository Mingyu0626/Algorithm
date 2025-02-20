#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    auto compare = [](int a, int b)
        {
            if (abs(a) == abs(b)) return a > b;
            else return abs(a) > abs(b);
        };
    priority_queue<int, vector<int>, decltype(compare)> pq(compare);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x != 0) pq.push(x);
        else
        {
            if (!pq.empty())
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else cout << 0 << '\n';
        }
    }
    return 0;
}