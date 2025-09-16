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

string solution(string number, int k) 
{
    int cnt = 0;
    while (cnt < k)
    {
        int n = number.size();
        for (int i = 1; i < n; ++i)
        {
            if (number[i - 1] < number[i])
            {
                number.erase(i - 1, 1);
                break;
            }
            else if (i == n - 1)
            {
                number.pop_back();
            }
        }
        cnt++;
    }
    return number;
}