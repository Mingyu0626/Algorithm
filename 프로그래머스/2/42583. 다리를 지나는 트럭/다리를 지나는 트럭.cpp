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

int solution(int bridgeLength, int weight, vector<int> truckWeights) 
{
    queue<pair<int, int>> q;
    int n = truckWeights.size();
    int curTime = 1, curWeight = 0, truckIndex = 0;
    while (truckIndex < n)
    {
        if (!q.empty() && q.front().second == curTime)
        {
            curWeight -= q.front().first;
            q.pop();
        }
        
        if (curWeight + truckWeights[truckIndex] <= weight && q.size() < bridgeLength)
        {
            int exitTime = curTime + bridgeLength;
            q.push({truckWeights[truckIndex], exitTime});
            curWeight += truckWeights[truckIndex], truckIndex++;
        }
        curTime++;
    }
    
    while (!q.empty())
    {
        curTime = q.front().second;
        q.pop();
    }
    return curTime;
}