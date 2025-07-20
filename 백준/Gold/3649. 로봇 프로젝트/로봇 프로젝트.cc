#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x, n;
bool canPlug;
const int CENTI_TO_NANO = 10000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin >> x)
    {
        x *= CENTI_TO_NANO;
        canPlug = false;
        cin >> n;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        int l = 0, r = n - 1;
        while (l < r)
        {
            int sum = v[l] + v[r];
            if (sum == x)
            {
                cout << "yes " << v[l] << ' ' << v[r] << '\n';
                canPlug = true;
                break;
            }
            else if (sum < x)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        if (!canPlug)
        {
            cout << "danger\n";
        }
    }
}