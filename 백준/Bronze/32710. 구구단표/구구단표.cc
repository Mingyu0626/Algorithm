#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (81 < n) cout << 0;
    else if (n < 10) cout << 1;
    else
    {
        bool isInTable = false;
        for (int i = 2; i <= 9; i++)
        {
            if (n % i == 0 && n / i < 10)
            {
                cout << 1;
                isInTable = true;
                break;
            }
        }
        if (!isInTable)
        {
            cout << 0;
        }
    }
    return 0;
}