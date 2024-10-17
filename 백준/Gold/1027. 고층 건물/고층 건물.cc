#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int n;
vector<int> v, result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    v.assign(n + 1, 0);
    result.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++)
    {
        double maxGrad = -1e9;
        for (int j = i + 1; j <= n; j++)
        {
            double gradient = (double)(v[j] - v[i]) / (j - i);
            if (maxGrad < gradient)
            {
                result[i]++, result[j]++;
                maxGrad = gradient;
            }
        }
    }
    cout << *max_element(result.begin(), result.end());
    return 0;
}