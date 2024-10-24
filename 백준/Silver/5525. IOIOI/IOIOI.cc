#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

int n, m, idx = 1, result;
bool isComplete = false;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> s;
    int targetSize = 0;
    char prev = s[0];
    if (prev == 'I') targetSize = 1;
    while (idx < m)
    {
        char cur = s[idx];
        if (prev == cur)
        {
            if (cur == 'I') targetSize = 1;
            else targetSize = 0;
            isComplete = false;
        }
        else
        {
            if (!isComplete)
            {
                targetSize++;
                if (targetSize == 2 * n + 1)
                {
                    isComplete = true;
                    result++;
                }
            }
            else if (cur == 'I')
            {
                result++;
            }
        }
        prev = s[idx];
        idx++;
    }
    cout << result;
    return 0;
}