#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int n, w, d, p, result;
string s;
vector<vector<vector<pair<string, int>>>> day;
map<string, int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    day.assign(11, vector<vector<pair<string, int>>>(7));
    for (int i = 0; i < n; i++)
    {
        cin >> s >> w >> d >> p;
        day[w][d].emplace_back(s, p);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> s >> p;
        m.insert({ s, p });
    }

    int cur = 0;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            bool canEat = false;
            for (int k = 0; k < day[i][j].size(); k++)
            {
                string curSenpai = day[i][j][k].first;
                int price = day[i][j][k].second;
                if (m.find(curSenpai) != m.end() && 0 <= m[curSenpai] - price)
                {
                    m[curSenpai] -= price;
                    canEat = true;
                }
            }
            if (canEat)
            {
                cur++;
            }
            else
            {
                result = max(result, cur);
                cur = 0;
            }
        }
    }
    result = max(result, cur);
    cout << result;
    return 0;
}