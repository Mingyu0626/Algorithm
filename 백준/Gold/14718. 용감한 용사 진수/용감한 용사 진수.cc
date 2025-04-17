#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct statInfo
{
    int STR, DEX, INT;
};
vector<statInfo> v;
int n, k, result = 1e9;
int curStr, curDex, curInt;

int calculateWinCount();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].STR >> v[i].DEX >> v[i].INT;
    }
    for (int strIdx = 0; strIdx < n; strIdx++)
    {
        curStr = v[strIdx].STR;
        for (int dexIdx = 0; dexIdx < n; dexIdx++)
        {
            curDex = v[dexIdx].DEX;
            for (int intIdx = 0; intIdx < n; intIdx++)
            {
                curInt = v[intIdx].INT;
                if (k <= calculateWinCount())
                {
                    result = min(result, curStr + curDex + curInt);
                }
            }
        }
    }
    cout << result;
    return 0;
}

int calculateWinCount()
{
    int winCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].STR <= curStr && v[i].DEX <= curDex && v[i].INT <= curInt)
        {
            winCount++;
        }
    }
    return winCount;
}