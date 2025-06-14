#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string s;
vector<string> suffix;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		string temp = s.substr(i, s.length() - i);
		suffix.push_back(temp);
	}
	sort(suffix.begin(), suffix.end());
	for (int i = 0; i < suffix.size(); i++) cout << suffix[i] << "\n";
	return 0;
}


