#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int distance, vector<int> rocks, int n) 
{
    sort(rocks.begin(), rocks.end());
    
    int l = 1, r = distance;
    int m, result = 0;
    while (l <= r)
    {
        m = (r - l) / 2 + l;
        
        int removedCnt = 0, prevRockPos = 0;
        for (int i = 0; i < rocks.size(); ++i)
        {
            if (rocks[i] - prevRockPos < m)
            {
                removedCnt++;
            }
            else
            {
                prevRockPos = rocks[i];
            }
        }
        if (distance - prevRockPos < m)
        {
            removedCnt++;
        }
        
        if (removedCnt <= n)
        {
            l = m + 1;
            result = max(result, m);
        }
        else
        {
            r = m - 1;
        }
    }
    return result;
}