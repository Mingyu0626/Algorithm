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

int result = 0;
vector<bool> v(10000000, true);
unordered_set<string> us;

void recursion(int idx, const string& s, string cur);

int solution(string s) 
{
    v[1] = false;
    for (int i = 2; i * i <= 10000000; ++i)
    {
        for (int j = i * 2; j <= 10000000; j += i)
        {
            v[j] = false;
        }
    }
    
    string temp = "";
    for (int i = 0; i < s.length(); ++i)
    {
        recursion(i, s, temp);
    }
    return result;
}

void recursion(int idx, const string& s, string cur)
{
    cur += s[idx];
    sort(cur.begin(), cur.end());
    do
    {
        if (cur[0] != '0' && v[stoi(cur)] && us.find(cur) == us.end())
        {
            us.insert(cur);
            result++;
        }
    } while (next_permutation(cur.begin(), cur.end()));
    
    for (int i = idx + 1; i < s.length(); ++i)
    {
        recursion(i, s, cur);
    }
}