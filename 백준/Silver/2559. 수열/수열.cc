#include <iostream>
#include <vector>

using namespace std;

int n, k, result, sum;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < k; i++) sum += v[i];

    result = sum;
    for (int i = k; i < n; i++)
    {
        sum -= v[i - k];
        sum += v[i];
        result = max(result, sum);
    }
    cout << result;
    return 0;
}