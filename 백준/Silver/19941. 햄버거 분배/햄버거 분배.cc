#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'P')
        {
            for (int j = max(i - k, 0); j <= i + k && j < n; j++)
            {
                if (s[j] == 'H')
                {
                    s[j] = '0';
                    result++;
                    break;
                }
            }
        }
    }
    cout << result;
    return 0;
}