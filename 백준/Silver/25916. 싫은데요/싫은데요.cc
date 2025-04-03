#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, sum, result;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    

    int l = 0, r = 0;
    bool isRChanged = true;
    while (l < n && r < n) 
    {
        if (isRChanged)
        {
            sum += v[r];

            if (m < v[r])
            {
                l = r;
                l++, r++;
                sum = 0;
                isRChanged = true;
            }
            else
            {
                isRChanged = false;
            }
        }

        else
        {
            if (sum <= m)
            {
                result = max(result, sum);
                r++;
                isRChanged = true;
            }
            else
            {
                sum -= v[l];
                l++;
                isRChanged = false;
            }
        }
    }
    cout << result;
    return 0;
}