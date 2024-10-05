#include <iostream>
#include <algorithm>
#include <string>

using namespace std; 

string l, r;
int result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> l >> r;
    for (int i = l.size() - 1; i >= 0; i--)
    {
        if (l[i] == r[i])
        {
            if (l[i] == '8')
            {
                result++;
            }
        }
        else result = 0;
    }

    if (r.size() > l.size()) result = 0;
    cout << result;
}