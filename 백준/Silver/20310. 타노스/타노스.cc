#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std; 

int n0, n1, cnt;
string s, result;
vector<bool> isDeleted(501, false);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0') n0++;
        else n1++;
    }
    n0 /= 2, n1 /= 2;

    for (int i = 0; i < s.size(); i++)
    {
        if (cnt == n1) break;
        if (s[i] == '1')
        {
            cnt++;
            isDeleted[i] = true;
        }
    }

    cnt = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (cnt == n0) break;
        if (s[i] == '0')
        {
            cnt++;
            isDeleted[i] = true;
        }
    }

    for (int i = 0; i < s.size(); i++)
        if (!isDeleted[i]) result += s[i];
    
    cout << result;
    return 0;
}