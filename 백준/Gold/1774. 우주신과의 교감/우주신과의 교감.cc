#define first f
#define second s
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

int n, m, a, b;
double result;
vector<pii> c;
vector<pair<double, pii>> v;
vector<int> parent;

int GetRoot(int a);
void Union(int a, int b);
bool IsSameParent(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    parent.assign(n + 1, 0);
    c.assign(n + 1, { 0, 0 });
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        cin >> c[i].f >> c[i].s;
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        if (!IsSameParent(a, b)) Union(a, b);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double dx = pow(abs(c[j].f - c[i].f), 2);
            double dy = pow(abs(c[j].s - c[i].s), 2);
            double dist = sqrt(dx + dy);
            v.push_back({ dist, { i, j } });
        }
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        double dist = v[i].f;
        int startGod = v[i].s.f;
        int endGod = v[i].s.s;
        if (!IsSameParent(startGod, endGod))
        {
            Union(startGod, endGod);
            result += dist;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << result;
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

bool IsSameParent(int a, int b)
{
    a = GetRoot(a);
    b = GetRoot(b);
    if (a == b) return true;
    else return false;
}