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

int solution(vector<int> v, int limit) 
{
    int n = v.size();
    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    int curSum = v[r], result = 1;
    while (l < r)
    {
        if (v[l] + curSum <= limit)
        {
            l++;
        }
        r--;
        if (l <= r)
        {
            result++;
            curSum = v[r];
        }
    }
    return result;
}