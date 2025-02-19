#include <iostream>
#include <map>

using namespace std;

int n, result;
map<int, int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int cur;
    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        m[cur]++;
    }

    for (auto& a : m)
    {
        result += (a.second <= 2 ? a.second : 2);
    }
    cout << result;
    return 0;
}