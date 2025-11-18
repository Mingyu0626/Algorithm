#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> v, int limit) 
{
    int n = v.size(), l = 0, r = n - 1;
    sort(v.begin(), v.end());
    int curSum = 0, result = 0;
    while (l <= r)
    {
        curSum = v[r], result++;
        if (v[l] + curSum <= limit)
        {
            l++;
        }
        r--;
    }
    return result;
}