#include <iostream>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    if (n % 7 == 1 || n % 7 == 3)
    {
        cout << "CY";
    }
    else
    {
        cout << "SK";
    }
    return 0;
}