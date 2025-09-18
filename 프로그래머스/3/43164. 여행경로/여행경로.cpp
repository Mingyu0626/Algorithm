#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string_view>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <ctime>
#include <bitset>
#include <cstdio>
#include <limits>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>

using namespace std;

int n;
unordered_map<string, vector<pair<string, bool>>> edges;

bool dfs(string cur, vector<string>& result);

vector<string> solution(vector<vector<string>> tickets) 
{
    n = tickets.size() + 1;
    for (int i = 0; i < tickets.size(); ++i)
    {
        edges[tickets[i][0]].emplace_back(tickets[i][1], false);
    }
    for (auto& v : edges)
    {
        sort(v.second.begin(), v.second.end());
    }
    
    vector<string> result;
    result.emplace_back("ICN");
    dfs("ICN", result);
    return result;
}

bool dfs(string cur, vector<string>& result)
{
    if (n == result.size())
    {
        return true;
    }
    
    for (int i = 0; i < edges[cur].size(); ++i)
    {
        string next = edges[cur][i].first;
        bool visited = edges[cur][i].second;
        if (!visited)
        {
            edges[cur][i].second = true;
            result.emplace_back(next);
            if (!dfs(next, result))
            {
                result.pop_back();
                edges[cur][i].second = false; 
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}