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

bool compare(const string& a, const string& b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) 
{
    int n = numbers.size();
    vector<string> v;
    for (int i = 0; i < n; ++i)
    {
        v.emplace_back(to_string(numbers[i]));
    }
    
    sort(v.begin(), v.end(), compare);
    string result = "";
    bool isAllZero = true;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] != "0")
        {
            isAllZero = false;
        }
        result.append(v[i]);
    }
    
    if (isAllZero)
    {
        return "0";
    }
    return result;
}