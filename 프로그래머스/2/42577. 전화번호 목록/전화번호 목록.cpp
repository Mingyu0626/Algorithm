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

unordered_set<string> us;

bool solution(vector<string> phone_book) 
{
    int n = phone_book.size();
    sort(phone_book.begin(), phone_book.end());
    for (int i = n - 1; i >= 0; --i)
    {
        string pre;
        for (int j = 0; j < phone_book[i].length(); ++j)
        {
            pre += phone_book[i][j];
            if (us.find(pre) == us.end())
            {
                us.insert(pre);
            }
            else if (j + 1 == phone_book[i].length())
            {
                return false;
            }
        }
    }
    return true;
}