#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

int n;
double sum;
vector<int> v;
unordered_map<int, int> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout.precision(0);
    cout << fixed;
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
        um[v[i]]++;
    }
    sort(v.begin(), v.end());
    cout << (int)round(sum / n) << '\n' << v[n / 2] << '\n';

    int curMaxFreq = 0;
    vector<int> freq;
    for (const auto& a : um)
    {
        if (curMaxFreq <= a.second)
        {
            if (curMaxFreq < a.second)
            {
                freq.clear();
                curMaxFreq = a.second;
            }
            freq.emplace_back(a.first);
        }
    }
    sort(freq.begin(), freq.end());
    if (1 < freq.size())
    {
        cout << freq[1] << '\n';
    }
    else
    {
        cout << freq[0] << '\n';
    }

    cout << *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
    return 0;
}