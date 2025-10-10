#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
using pii = pair<int, int>;

bool compare(const pii& a, const pii& b)
{
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    return a.second > b.second;
}

int solution(vector<vector<int>> targets) 
{
    vector<pii> v;
    int n = targets.size(), result = 1;
    for (int i = 0; i < n; ++i)
    {
        v.emplace_back(targets[i][0], targets[i][1]);
    }
    sort(v.begin(), v.end(), compare);

    int s = v[0].first, e = v[0].second;
    for (int i = 1; i < n; ++i)
    {
        int curS = v[i].first, curE = v[i].second;
        if (s < curE)
        {
            s = (s < curS) ? curS : s;
            e = curE;
        }
        else
        {
            result++;
            s = curS, e = curE;
        }
    }
    return result;
}