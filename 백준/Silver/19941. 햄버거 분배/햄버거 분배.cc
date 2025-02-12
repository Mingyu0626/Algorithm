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

    vector<bool> eated(n, false);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'P')
        {
            bool canEat = false;
            int leftIdx = max(i - k, 0);
            for (int j = leftIdx; j < i; j++)
            {
                if (s[j] == 'H' && !eated[j])
                {
                    eated[j] = true;
                    canEat = true;
                    result++;
                    break;
                }
            }

            if (!canEat)
            {
                for (int j = i + 1; j < n && j <= i + k; j++)
                {
                    if (s[j] == 'H' && !eated[j])
                    {
                        eated[j] = true;
                        result++;
                        break;
                    }
                }
            }
        }
    }
    cout << result;
    return 0;
}