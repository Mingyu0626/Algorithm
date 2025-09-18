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

int solution(int k, vector<vector<int>> dungeons) 
{
    vector<pair<int, int>> v;
    int n = dungeons.size();
    for (int i = 0; i < n; ++i)
    {
        v.emplace_back(dungeons[i][0], dungeons[i][1]);
    }
    
    sort(v.begin(), v.end());
    int result = 0;
    do
    {
        int curK = k, cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (v[i].first <= curK)
            {
                curK -= v[i].second;
                cnt++;
            }
            else
            {
                break;
            }
        }
        result = max(result, cnt);   
    } while (next_permutation(v.begin(), v.end()));
    
    return result;
}