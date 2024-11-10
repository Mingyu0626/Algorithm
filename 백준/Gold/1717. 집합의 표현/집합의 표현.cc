#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int parent[1000001];

int GetRoot(int a);
void Union(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    int oper, a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> oper >> a >> b;
        if (oper == 0)
        {
            Union(a, b);
        }
        else
        {
            if (GetRoot(a) == GetRoot(b))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}

int GetRoot(int a)
{
    if (parent[a] == a) return a;
    else return parent[a] = GetRoot(parent[a]);
}

void Union(int a, int b)
{
    a = GetRoot(a);
    b = GetRoot(b);
    if (a != b) parent[b] = a;
}