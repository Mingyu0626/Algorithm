#include <iostream>
#include <vector>

using namespace std;

int n;
vector<bool> v(300001, true);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    v[1] = false;
    for (int i = 2; i * i < v.size(); ++i)
    {
        for (int j = i * i; j < v.size(); j += i)
        {
            if (v[j])
            {
                v[j] = false;
            }
        }
    }

    while (cin >> n && n != 0)
    {
        int result = 0;
        for (int i = n + 1; i <= n * 2; ++i)
        {
            result += (v[i]) ? 1 : 0;
        }
        cout << result << '\n';
    }
    return 0;
}