#include <iostream>
#include <algorithm>

using namespace std;

int n, k, target;

int recursion(int val, int curN);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    while (0 < k)
    {

        target = recursion(1, n);
        n -= target;
        if (n == 0)
        {
            target = 0;
            break;
        }
        k--;
    }
    cout << target - n;
    return 0;
}

int recursion(int val, int curN)
{
    if (val * 2 > curN) return val;
    else return recursion(val * 2, curN);
}
