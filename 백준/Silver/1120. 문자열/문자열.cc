#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int x, y, result = 51;
string a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;
    for (int i = 0; i < b.size() - a.size() + 1; i++)
    {
        int cur = 0;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] != b[i + j]) cur++;
        }
        result = min(result, cur);
    }
    cout << result;
    return 0;
}