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

long long solution(int n, vector<int> times) 
{
    long long result = LLONG_MAX;
    long long l = 1, r = 1e9 * 1e9;
    long long m;
    while (l <= r)
    {
        m = (r - l) / 2 + l;
        long long cnt = 0;
        for (int i = 0; i < times.size(); ++i)
        {
            cnt += m / times[i];
        }
        
        if (cnt < n)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
            result = min(result, m);
        }
    }
    return result;
}