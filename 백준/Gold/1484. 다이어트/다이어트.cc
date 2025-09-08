#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int g, curG, l, r;
bool hasResult;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> g;

    l = 1, r = 2;
    while (l < r)
    {
        curG = pow(r, 2) - pow(l, 2);

        if (curG <= g && curG <= 100000)
        {
            if (curG == g)
            {
                cout << r << '\n';
                hasResult = true;
            }
            r++;
        }
        else
        {
            l++;
        }
    }
    
    if (!hasResult)
    {
        cout << -1;
    }
    return 0;
}