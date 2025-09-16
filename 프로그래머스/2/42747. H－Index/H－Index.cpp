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

int solution(vector<int> v) 
{
    int n = v.size(), result = 0;
    sort(v.begin(), v.end());
    int l = 0, r = *max_element(v.begin(), v.end());
    while (l <= r)
    {
        int m = (r - l) / 2 + l;
        
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            cnt += (m <= v[i]) ? 1 : 0;
        }
        
        if (cnt < m)
        {
            r = m - 1;
        }
        else
        {
            result = max(result, m);
            l = m + 1;
        }
    }
    return result;
}