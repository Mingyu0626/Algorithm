#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a, b;
int parent[500001];

int GetRoot(int a);
bool Union(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        if (!Union(a, b))
        {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}

int GetRoot(int a)
{
    if (parent[a] == a) return a;
    else return parent[a] = GetRoot(parent[a]);
}

bool Union(int a, int b)
{
    a = GetRoot(a);
    b = GetRoot(b);
    if (a == b) return false;
    if (a != b) parent[b] = a;
    return true;
}