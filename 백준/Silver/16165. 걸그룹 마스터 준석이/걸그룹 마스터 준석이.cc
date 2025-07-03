#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int n, m, num;
string girlGroupName, memberName, name;
map<string, vector<string>> groupTreeMap;
map<string, string> memberTreeMap;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> girlGroupName >> num;
        groupTreeMap[girlGroupName] = vector<string>();
        for (int j = 0; j < num; j++)
        {
            cin >> memberName;
            groupTreeMap[girlGroupName].emplace_back(memberName);
            memberTreeMap[memberName] = girlGroupName;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> name >> num;
        if (num == 0)
        {
            sort(groupTreeMap[name].begin(), groupTreeMap[name].end());
            for (int j = 0; j < groupTreeMap[name].size(); j++)
            {
                cout << groupTreeMap[name][j] << '\n';
            }
        }
        else
        {
            cout << memberTreeMap[name] << '\n';
        }
    }
    return 0;
}