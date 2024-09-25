#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, q, duck, result;
vector<bool> visited;
vector<int> v;
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
        go(duck);
        if (v.size() == 0) cout << 0 << '\n';
        else cout << v[v.size() - 1] << '\n';
        visited[duck] = true;
        v.clear();
    }
    return 0;
}

void go(int d)
{
    if (visited[d]) v.push_back(d);
    if (d > 1) go(d / 2);
}
