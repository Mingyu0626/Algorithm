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

unordered_map<string, vector<pair<int, int>>> um;

bool compareVectorSize(const vector<pair<int, int>>& a, const vector<pair<int, int>>& b);
bool compare(const pair<int, int>& a, const pair<int, int>& b);

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> result;
    int n = genres.size();
    for (int i = 0; i < n; ++i)
    {
        um[genres[i]].emplace_back(plays[i], i);
    }
    
    vector<vector<pair<int, int>>> allMusics;
    for (const auto& a : um)
    {
        allMusics.emplace_back(a.second);
    }
    sort(allMusics.begin(), allMusics.end(), compareVectorSize);
    
    for (int i = 0; i < allMusics.size(); ++i)
    {
        sort(allMusics[i].begin(), allMusics[i].end(), compare);
        for (int j = 0; j < allMusics[i].size(); ++j)
        {
            if (j < 2)
            {
                result.emplace_back(allMusics[i][j].second);
            }
        }
    }
    return result;
}

bool compareVectorSize(const vector<pair<int, int>>& a, const vector<pair<int, int>>& b)
{
    long long aSum = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        aSum += a[i].first;
    }
    
    long long bSum = 0;
    for (int i = 0; i < b.size(); ++i)
    {
        bSum += b[i].first;
    }
    return aSum > bSum;
}

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}