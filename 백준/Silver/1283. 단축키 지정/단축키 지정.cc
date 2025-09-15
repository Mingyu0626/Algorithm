#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <limits>
#include <sstream>

using namespace std;
template <typename T>
using Dim2Vec = vector<vector<T>>;

int n;
string line, s;
Dim2Vec<string> v;
unordered_set<char> us;

void setShortcut(int idx);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    v.assign(n, vector<string>());
    for (int i = 0; i < n; ++i)
    {
        getline(cin, line);
        stringstream ss(line);
        while (ss >> s)
        {
            v[i].emplace_back(s);
        }

        setShortcut(i);
        for (const auto& a : v[i])
        {
            cout << a << ' ';
        }
        cout << '\n';
    }
    return 0;
}

void setShortcut(int idx)
{
    for (int i = 0; i < v[idx].size(); ++i)
    {
        char firstLetter = v[idx][i][0];
        if (us.find(firstLetter) == us.end())
        {
            if (firstLetter < 'a')
            {
                us.insert(firstLetter + 32);
            }
            else
            {
                us.insert(firstLetter - 32);
            }
            us.insert(firstLetter);

            v[idx][i].insert(v[idx][i].begin() + 1, ']');
            v[idx][i].insert(v[idx][i].begin(), '[');
            return;
        }
    }

    for (int i = 0; i < v[idx].size(); ++i)
    {
        for (int j = 0; j < v[idx][i].length(); ++j)
        {
            char cur = v[idx][i][j];
            if (us.find(cur) == us.end())
            {
                if (cur < 'a')
                {
                    us.insert(cur + 32);
                }
                else
                {
                    us.insert(cur - 32);
                }
                us.insert(cur);

                v[idx][i].insert(v[idx][i].begin() + j + 1, ']');
                v[idx][i].insert(v[idx][i].begin() + j, '[');
                return;
            }
        }
    }
}