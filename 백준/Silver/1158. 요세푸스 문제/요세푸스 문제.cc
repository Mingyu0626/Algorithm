#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    cout << '<';
    while (1 < q.size())
    {
        int cnt = 1;
        while (cnt < k)
        {
            int cur = q.front();
            q.pop();
            q.push(cur);
            cnt++;
        }
        cout << q.front();
        q.pop();
        cout << ", ";
    }

    cout << q.front() << '>';
    return 0;
}