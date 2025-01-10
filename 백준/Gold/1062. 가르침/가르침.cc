#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

int n, k, result;
vector<string> v;
array<bool, 26> a;

void recursion(const int idx, const int cnt);
void checkReadableString();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    v.assign(n, string());
    a['a' - 97] = a['n' - 97] = a['t' - 97] = a['i' - 97] = a['c' - 97] = true;
    for (int i = 0; i < n; i++) cin >> v[i];
    if (4 < k)
    {
        k -= 5;
        recursion(0, 0);
    }
    cout << result;
    return 0;
}

void recursion(const int idx, const int cnt)
{
    if (cnt == k)
    {
        checkReadableString();
        return;
    }
    for (int i = idx; i < 26; i++)
    {
        if (!a[i])
        {
            a[i] = true;
            recursion(i, cnt + 1);
            a[i] = false;
        }
    }
}

void checkReadableString()
{
    int res = 0;
    bool readable;
    for (int i = 0; i < n; i++)
    {
        readable = true;
        for (int j = 4; j < v[i].length() - 4; j++)
        {
            if (!a[v[i][j] - 97])
            {
                readable = false;
                break;
            }
        }
        if (readable) res++;
    }
    result = max(result, res);
}