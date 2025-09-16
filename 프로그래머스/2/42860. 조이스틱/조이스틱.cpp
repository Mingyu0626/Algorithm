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

int solution(string name) 
{
    int result = 0, n = name.length(), horizontalMove = 1e9;
    for (int i = 0; i < n; ++i)
    {
        result += 'N' < name[i] ? 26 - (name[i] - 'A') : name[i] - 'A';
        int nextNotAIdx = i + 1;
        while (nextNotAIdx < n && name[nextNotAIdx] == 'A')
        {
            nextNotAIdx++;
        }
        horizontalMove = 
            min({i + i + (n - nextNotAIdx), 
                i + (n - nextNotAIdx) + (n - nextNotAIdx),
                horizontalMove});
    }

    return result + horizontalMove;
}