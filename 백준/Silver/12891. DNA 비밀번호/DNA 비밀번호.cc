#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int s, p, num, result;
string str;
map<char, int> dna({ {'A', 0}, {'C', 0}, {'G', 0}, {'T', 0} });
map<char, int> current({ {'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}});

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s >> p >> str;
    for (auto& a : dna) cin >> a.second;
    for (int i = 0; i < p; i++) current[str[i]]++;

	int l = 0, r = p - 1;
    while (r < s)
    {
		bool isDNA = true;
        for (auto& a : dna)
        {
            if (current[a.first] < a.second)
            {
				isDNA = false;
                break;
            }
        }
        if (isDNA)
        {
            result++;
        }
        if (current.find(str[l]) != current.end())
        {
            current[str[l]]--;
        }
        l++, r++;
        if (current.find(str[r]) != current.end())
        {
            current[str[r]]++;
        }
    }
    cout << result;
    return 0;
}