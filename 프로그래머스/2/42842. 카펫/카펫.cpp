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

vector<int> solution(int brown, int yellow) 
{
    vector<int> result(2, 0);
    for (int c = 3; c <= 2000; ++c)
    {
        for (int r = c; r <= 2000; ++r)
        {
            if ((r - 2) * (c - 2) == yellow &&
               2 * r + 2 * c - 4 == brown)
            {
                result[0] = r, result[1] = c;
                break;
            }
        }
    }
    return result;
}