#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n, t;
int minNum[7] = {0, 0, 1, 7, 4, 2, 6};
int minNum2[7] = {0, 10, 18, 22, 20, 28, 68};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        int minRest = 0, maxRest = 0;

        if (n % 7 > 0)
        {
            if (n / 7 == 0) cout << minNum[n % 7];
            else
            {
                if (n / 7 > 1 && n % 7 == 3)
                {
                    cout << 200;
                    minRest = 2;
                }
                else 
                {
                    cout << minNum2[n % 7];
                    minRest = 1;
                }
            }
        }
        for (int i = 1; i <= (n / 7) - minRest; i++) cout << 8;
        

        cout << " ";
        if (n % 2 == 1)
        {
            maxRest = 1;
            cout << 7;
        }
        for (int i = 1; i <= (n / 2) - maxRest; i++) cout << 1;

        t--;
        cout << "\n";
    }
    return 0;
}
