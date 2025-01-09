#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <set>
#include <cmath>

using namespace std;

int timeNum = 10000, result = 1;
array<int, 4> a;
set<int> s;

void recursion(const string curCard, const int cnt);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < a.size(); i++) cin >> a[i];
    for (int i = 0; i < a.size(); i++)
    {
        int curNum = 0;
        for (int j = 0; j < a.size(); j++)
        {
            curNum += a[(j + i) % 4] * pow(10, 3 - j);
        }
        timeNum = min(timeNum, curNum);
    }

    for (int i = 1; i <= 9; i++)
    {
        char c = i + '0';
        string str{c};
        recursion(str, 1);
    }

    for (auto& i : s)
    {
        if (timeNum == i) break;
        result++;
    }

    cout << result;
    return 0;
}

void recursion(const string curCard, const int cnt)
{
    if (cnt == 4)
    {
        int timeNumber = 10000;
        for (int i = 0; i < cnt; i++)
        {
            int curNum = 0;
            for (int j = 0; j < cnt; j++)
            {
                curNum += (curCard[(j + i) % 4] - '0') * pow(10, 3 - j);
            }
            timeNumber = min(timeNumber, curNum);
        }
        s.insert(timeNumber);
        return;
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            char c = i + '0';
            recursion(curCard + c, cnt + 1);
        }
    }
}