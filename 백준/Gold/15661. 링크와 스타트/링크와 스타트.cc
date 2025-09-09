#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int n, sum, result = 1e9;
Dim2Vec<int> v;

void makeTeam(unordered_set<int>& teamHashSet, int num);
void calc(const unordered_set<int>& teamHashSet);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> v[i][j];
            sum += v[i][j];
        }
    }

    unordered_set<int> team;
    team.insert(1);
    makeTeam(team, 1);

    cout << result;
    return 0;
}

void makeTeam(unordered_set<int>& teamHashSet, int num)
{
    if (teamHashSet.size() == n)
    {
        return;
    }

    calc(teamHashSet);

    for (int i = num + 1; i <= n; ++i)
    {
        teamHashSet.insert(i);
        makeTeam(teamHashSet, i);
        teamHashSet.erase(i);
    }
}

void calc(const unordered_set<int>& teamHashSet)
{
    vector<int> startTeams;
    for (const auto& a : teamHashSet)
    {
        startTeams.emplace_back(a);
    }
    sort(startTeams.begin(), startTeams.end());
    int startTeam = 0;
    for (int i = 0; i < startTeams.size(); ++i)
    {
        for (int j = i + 1; j < startTeams.size(); ++j)
        {
            int a = startTeams[i], b = startTeams[j];
            startTeam += v[a][b] + v[b][a];
        }
    }

    vector<int> linkTeams;
    for (int i = 1; i <= n; ++i)
    {
        if (teamHashSet.find(i) == teamHashSet.end())
        {
            linkTeams.emplace_back(i);
        }
    }
    int linkTeam = 0;
    for (int i = 0; i < linkTeams.size(); ++i)
    {
        for (int j = i + 1; j < linkTeams.size(); ++j)
        {
            int a = linkTeams[i], b = linkTeams[j];
            linkTeam += v[a][b] + v[b][a];
        }
    }

    result = min(result, abs(linkTeam - startTeam));
}