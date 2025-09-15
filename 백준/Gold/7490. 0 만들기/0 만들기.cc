#include <iostream>
#include <string>

using namespace std;

int t, n;
bool hasResult;

enum Behavior
{
    Connect,
    Add,
    Sub,
};

void search(int cnt, int sum, int lastNum, string cur, Behavior behavior);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (cin >> n)
    {
        if (hasResult)
        {
            cout << '\n';
        }
        string cur{ "1" };
        hasResult = false;
        search(2, 1, 1, cur, Connect);
        search(2, 1, 1, cur, Add);
        search(2, 1, 1, cur, Sub);
    }
    return 0;
}

void search(int cnt, int sum, int lastNum, string cur, Behavior behavior)
{
    switch (behavior)
    {
    case Connect:
        sum += lastNum * 9, lastNum += lastNum * 9;
        if (lastNum < 0)
        {
            sum -= cnt;
            lastNum -= cnt;
        }
        else
        {
            sum += cnt;
            lastNum += cnt;
        }
        cur += ' ';
        break;

    case Add:
        sum += cnt, lastNum = cnt;
        cur += '+';
        break;
    case Sub:
        sum -= cnt, lastNum = -cnt;
        cur += '-';
        break;
    }
    cur += (char)(cnt + '0');

    if (cnt < n)
    {
        search(cnt + 1, sum, lastNum, cur, Connect);
        search(cnt + 1, sum, lastNum, cur, Add);
        search(cnt + 1, sum, lastNum, cur, Sub);
    }
    else if (sum == 0)
    {
        cout << cur << '\n';
        hasResult = true;
    }
}