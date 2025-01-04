#include <iostream>
#include <algorithm>

using namespace std; 

int t, n;
long long prefix[65][11];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;

    for (int i = 1; i <= 10; i++) prefix[1][i] = i;

    for (int i = 2; i <= 64; i++)
    {
        prefix[i][1] = 1;
        for (int j = 2; j <= 10; j++)
        {
            prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j];
        }
    }

    while (0 < t--)
    {
        cin >> n;
        cout << prefix[n][10] << '\n';
    }
    return 0;
}