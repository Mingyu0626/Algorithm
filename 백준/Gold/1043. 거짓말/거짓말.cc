#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, t, tmp, num, result;
vector<int> parent, truthPerson;
vector<vector<int>> party;
vector<bool> canKnowTruth;

int GetRoot(int a);
void Union(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;
    parent.assign(n + 1, 0), truthPerson.assign(t, 0);
    party.assign(m, vector<int>());
    canKnowTruth.assign(n + 1, false);
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < t; i++) 
    { 
        cin >> truthPerson[i];
        canKnowTruth[truthPerson[i]] = true;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        party[i].assign(num, 0);
        int prev = 0, cur;
        for (int j = 0; j < num; j++)
        {
            cin >> cur;
            party[i][j] = cur;
            if (prev != 0)
            {
                Union(prev, cur);
            }
            prev = cur;
        }
    }

    for (int i = 0; i < t; i++)
    {
        canKnowTruth[GetRoot(truthPerson[i])] = true;
    }

    for (int i = 0; i < m; i++)
    {
        bool canLie = true;
        for (int j = 0; j < party[i].size(); j++)
        {
            if (canKnowTruth[GetRoot(party[i][j])])
            {
                canLie = false;
                break;
            }
        }
        if (canLie) result++;
    }
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