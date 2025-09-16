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

vector<int> solution(vector<int> prices) 
{
    
    stack<pair<int, int>> s;
    int n = prices.size();
    vector<int> result(n, 0);
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && prices[i] < s.top().first)
        {
            result[s.top().second - 1] = i - s.top().second + 1;
            s.pop();
        }
        s.push({prices[i], i + 1});
    }
    
    while (!s.empty())
    {
        result[s.top().second - 1] = n - s.top().second;
        s.pop();
    }
    return result;
}