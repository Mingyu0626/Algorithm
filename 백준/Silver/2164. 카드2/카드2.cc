#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) q.push(i);
    while (q.size() > 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
    return 0;
}