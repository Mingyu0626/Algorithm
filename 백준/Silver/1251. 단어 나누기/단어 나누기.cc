#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int l;
string s, result = "|";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    l = s.size();
    for (int i = 0; i < l - 2; i++)
    {
        for (int j = i + 1; j < l - 1; j++)
        {
            string str;
            for (int k = i; k >= 0; k--) str += s[k];
            for (int k = j; k >= i + 1; k--) str += s[k];
            for (int k = l - 1; k >= j + 1; k--) str += s[k];
            if (str < result) result = str;
        }
    }
    cout << result;
    return 0;
}