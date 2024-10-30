#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <limits.h>

using namespace std;

struct star
{
    float x, y;
};

struct edge
{
    edge(int s, int e, float d)
        :s(s), e(e), d(d) {}
    int s, e; 
    float d;

    bool operator<(edge& e)
    {
        return this->d < e.d;
    }
};

int n;
vector<star> stars;
vector<edge> v;
int parent[101];
float result;

int GetRoot(int a);
void Union(int a, int b);
bool IsSameParent(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    stars.assign(n + 1, { 0, 0 });
    for (int i = 1; i <= n; i++)
    {
        cin >> stars[i].x >> stars[i].y;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            float dist =
                sqrt(pow((abs(stars[i].x - stars[j].x)), 2) + 
                    pow((abs(stars[i].y - stars[j].y)), 2));
            v.push_back(edge(i, j, dist));
        }
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) parent[i] = i;

    for (int i = 0; i < v.size(); i++)
    {
        int start = v[i].s;
        int end = v[i].e;
        float dist = v[i].d;

        if (!IsSameParent(start, end))
        {
            Union(start, end);
            result += dist;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << result;
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

bool IsSameParent(int a, int b)
{
    a = GetRoot(a);
    b = GetRoot(b);
    if (a == b) return true;
    else return false;
}