#include <iostream>

using namespace std;

int n, k;
long long result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin >> n >> k)
    {
        if (n == 0 && k == 0)
        {
            break;
        }
        if (n / 2 < k)
        {
            k = n - k;
        }

        result = 1;
        n -= k;
        int div = 1;
        for (int i = 1; i <= k; i++)
        {
            result *= (n + i);
            if (result % i == 0)
            {
                result /= i;
            }
            else
            {
                div *= i;
            }

            if (result % div == 0)
            {
                result /= div;
                div = 1;
            }
        }
        cout << result << '\n';
    }
    return 0;
}