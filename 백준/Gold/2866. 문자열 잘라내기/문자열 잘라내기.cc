#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std; 

int r, c, cnt;
string v[1000];
vector<string> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> v[i];

    for (int i = 0; i < c; i++)
    {
        string str;
        for (int j = r - 1; j >= 0; j--)
        {
            str += v[j][i];
        }
        s.push_back(str);
    }

    for (int i = 1; i < r; i++)
    {
        unordered_set<string> us;
        for (int j = 0; j < c; j++)
        {
            s[j].pop_back();
            if (us.find(s[j]) == us.end())
            {
                us.insert(s[j]);
            }
            else
            {
                cout << cnt;
                exit(0);
            }
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}