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

int dp[1000001][2][2];

int solution(vector<int> money) 
{
    int n = money.size();
    dp[1][1][1] = money[0];
    for (int i = 2; i <= n; ++i)
    {
        dp[i][1][1] = max(dp[i - 1][0][1], dp[i - 2][1][1]) + money[i - 1]; 
        dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][1]);
        
        dp[i][1][0] = max(dp[i - 1][0][0], dp[i - 2][1][0]) + money[i - 1]; 
        dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][1][0]);
    }
    
    dp[n][1][1] -= money[n - 1];
    
    return max({dp[n][0][1], dp[n][1][1], dp[n][0][0], dp[n][1][0]});
}