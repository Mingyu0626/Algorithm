#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long a, b;
long long calculate(long long target);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;

    cout << calculate(b) - calculate(a - 1) << '\n';
    return 0;
}

long long calculate(long long target)
{
    long long curResult = 0, curVal = 1;
    int bitNum = 0;
    while (curVal <= target)
    {
        long long num = target - curVal + 1;
        long long sq = (long long)pow(2, bitNum);
        long long val = num / sq;
        long long rest = num % sq;

        if (val % 2 == 0)
        {
            curResult += rest;
        }
        if (0 < val)
        {
            long long quo = (val / 2) + (val % 2);
            curResult += quo * sq;
        }

        bitNum++, curVal *= 2;
    }
    return curResult;
}