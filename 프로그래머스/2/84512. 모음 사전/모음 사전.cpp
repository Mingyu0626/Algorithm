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

vector<char> vowels = {'A', 'E', 'I', 'O', 'U'};
vector<string> words;

void recursion(string cur, int idx);


int solution(string word) 
{
    string temp = "";
    recursion(temp, 0);
    sort(words.begin(), words.end());
    return find(words.begin(), words.end(), word) - words.begin();
}

void recursion(string cur, int idx)
{
    do
    {
        words.emplace_back(cur);
    } while (next_permutation(cur.begin(), cur.end()));
    
    if (cur.length() == 5)
    {
        return;
    }
    
    for (int i = idx; i < 5; ++i)
    {
        recursion(cur + vowels[i], i);
    }
}