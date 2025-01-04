#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, m, t, a, b, result;
int parent[501];

int GetRoot(int a);
void Union(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        t++, result = 0;
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            Union(a, b);
        }

        for (int i = 1; i <= n; i++)
        {
            if (parent[i] == i)
            {
                result++;
            }
        }
        cout << "Case " << t << ": ";
        if (result == 0) cout << "No trees.\n";
        else if (result == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << result << " trees.\n";
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
    if (a != b)
    {
        if (a < b) parent[b] = a;
        else parent[a] = b;
    }
    else
    {
        parent[a] = 0;
        parent[b] = 0;
    }
}