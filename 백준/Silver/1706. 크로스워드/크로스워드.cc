#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int r, c;
vector<vector<char>> v;
set<string> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> r >> c;
    v.assign(r, vector<char>(c));
    for (int i = 0; i < r; i++)
    {
        string word;
        for (int j = 0; j < c; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == '#')
            {
                if (1 < word.length()) s.emplace(word);
                word.clear();
            }
            else word += v[i][j];
        }
        if (1 < word.length()) s.emplace(word);
    }

    for (int i = 0; i < c; i++)
    {
        string word;
        for (int j = 0; j < r; j++)
        {
            if (v[j][i] == '#')
            {
                if (1 < word.length()) s.emplace(word);
                word.clear();
            }
            else word += v[j][i];
        }
        if (1 < word.length()) s.emplace(word);
    }

    for (auto& a : s)
    {
        cout << a;
        break;
    }
    return 0;
}