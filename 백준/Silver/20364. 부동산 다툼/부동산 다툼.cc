#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, q, duck, last;
vector<bool> visited;
void go(int d);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    visited.assign(n + 1, false);
    for (int i = 0; i < q; i++)
    {
        cin >> duck;
        last = 0;
        go(duck);
        cout << last << '\n';
        visited[duck] = true;
    }
    return 0;
}

void go(int d)
{
    if (visited[d]) last = d;
    if (d > 1) go(d / 2);
}