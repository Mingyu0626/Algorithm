#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, k;

void recursion(int n, int start, int mid, int dest)
{
    if (n == 1) cout << start << ' ' << dest << '\n';
    else
    {
        recursion(n - 1, start, dest, mid);
        cout << start << ' ' << dest << '\n';
        recursion(n - 1, mid, start, dest);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    k = pow(2, n) - 1;
    cout << k << '\n';
    recursion(n, 1, 2, 3);
    return 0;
}