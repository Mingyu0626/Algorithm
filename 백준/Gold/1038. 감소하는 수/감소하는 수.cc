#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
vector<long long> resultList;

void makeResult(long long num, int digits);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < 10; i++)
    {
        makeResult(i, 1);
    }

    sort(resultList.begin(), resultList.end());
    if (resultList.size() <= n)
    {
        cout << -1;
    }
    else
    {
        cout << resultList[n];
    }
    return 0;
}

void makeResult(long long num, int digits)
{
    if (10 < digits)
    {
        return;
    }

    resultList.emplace_back(num);

    for (int i = 0; i < 10; i++)
    {
        if (i < num % 10)
        {
            makeResult(num * 10 + i, digits + 1);
        }
    }
}