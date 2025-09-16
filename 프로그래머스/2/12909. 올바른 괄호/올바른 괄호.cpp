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

bool solution(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (!st.empty())
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }
    return st.empty();
}