#include <iostream>

using namespace std;

int a, k, result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> k;
    while (a != k)
    {
        if (k % 2 == 1)
        {
            k -= 1;
        }
        else if (a <= k / 2)
        {
            k /= 2;
        }
        else
        {
            k -= 1;
        }
        result++;
    }
    cout << result;
}