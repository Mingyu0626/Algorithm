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

unordered_map<string, vector<string>> um;

int solution(vector<vector<string>> clothes) 
{
    for (int i = 0; i < clothes.size(); ++i)
    {
        um[clothes[i][1]].emplace_back(clothes[i][0]);
    }
    
    int result = 1;
    for (const auto& a : um)
    {
        result *= a.second.size() + 1;
    }
    return result - 1;
}