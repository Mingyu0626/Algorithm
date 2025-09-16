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

vector<int> solution(vector<int> arr) 
{
    stack<int> s;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (s.empty() || s.top() != arr[i])
        {
            s.push(arr[i]);
        }
    }
    vector<int> answer;
    while (!s.empty())
    {
        answer.emplace_back(s.top());
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}