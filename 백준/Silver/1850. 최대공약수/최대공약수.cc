#include <iostream>
#include <numeric>

using namespace std;

long long a, b, GCD;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;
    GCD = gcd(a, b);
    for (int i = 0; i < GCD; ++i)
    {
        cout << 1;
    }
    return 0;
}