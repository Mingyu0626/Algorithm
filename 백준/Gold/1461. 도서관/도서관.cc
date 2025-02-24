#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, temp, maxDis, result;
vector<int> v1, v2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        maxDis = max(maxDis, abs(temp));
        if (temp > 0) v1.push_back(temp);
        else v2.push_back(temp);
    }
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end());
    
    for (int i = 0; i < v1.size(); i += m) result += v1[i] * 2;
    for (int i = 0; i < v2.size(); i += m) result += abs(v2[i]) * 2;

    result -= maxDis;
    cout << result;
    return 0;
}