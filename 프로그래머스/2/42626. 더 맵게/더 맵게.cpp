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

int solution(vector<int> scoville, int K) 
{
    priority_queue<long long> pq;
    
    for (int i = 0; i < scoville.size(); ++i)
    {
        pq.push(-scoville[i]);
    }
    
    int cnt = 0;
    while (2 <= pq.size())
    {
        if (K <= -pq.top())
        {
            return cnt;
        }
        
        long long first = -pq.top();
        pq.pop();
        long long second = -pq.top();
        pq.pop();
        pq.push(-(first + second * 2));
        
        cnt++;
    }
    
    if (!pq.empty() && K <= -pq.top())
    {
        return cnt;
    }
    return -1;
}