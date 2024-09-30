#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e, result;
int parent[10001];
vector<pair<int, pair<int, int>>> r;

int getRoot(int a);
void Union(int a, int b);
bool isSameParent(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> v >> e;
    r.assign(e, { 0, {0, 0} });

    for (int i = 0; i < e; i++)
        cin >> r[i].second.first >> r[i].second.second >> r[i].first;
    
    sort(r.begin(), r.end());

    for (int i = 1; i <= v; i++) parent[i] = i;

    for (int i = 0; i < e; i++)
    {
        int cost = r[i].first;
        int start = r[i].second.first;
        int dest = r[i].second.second;

        if (!isSameParent(start, dest))
        {
            Union(start, dest);
            result += cost;
        }
    }

    cout << result;
    return 0;
}

int getRoot(int a)
{
    if (parent[a] == a) return a;
    else return parent[a] = getRoot(parent[a]);
}

void Union(int a, int b)
{
    a = getRoot(a);
    b = getRoot(b);
    if (a != b) parent[b] = a;
}

bool isSameParent(int a, int b)
{
    a = getRoot(a);
    b = getRoot(b);
    if (a == b) return true;
    else return false;
}
