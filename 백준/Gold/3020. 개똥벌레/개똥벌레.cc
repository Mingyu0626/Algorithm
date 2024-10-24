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
int n, h, a;
vector<int> v1, v2;
int result = 1e9, num;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> h;
    v1.assign(h + 1, 0), v2.assign(h + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (i % 2 == 0) v1[a]++;
        else v2[a]++;
    }

    for (int i = h; i >= 2; i--)
    {
        v1[i - 1] += v1[i];
        v2[i - 1] += v2[i];
    }

    reverse(v2.begin() + 1, v2.end());
    for (int i = 1; i <= h; i++)
    {

        int cur = v1[i] + v2[i];
        if (cur == result) num++;
        if (cur < result)
        {
            result = cur;
            num = 1;
        }
    }
    cout << result << ' ' << num;
    return 0;
}