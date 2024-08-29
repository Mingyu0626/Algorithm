#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

int n, d, k, c, num, result;
vector<int> v;
unordered_map<int, int> um;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> d >> k >> c;
	v.assign(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = 0; i < k; i++)
	{
		if (um[v[i]] == 0) num++;
		um[v[i]]++;
	}

	if (um[c] == 0) result = num + 1;
	else result = num;

	int left = 1, right = k;
	while (n != k && left < n)
	{
		if (um[v[left - 1]] == 1) num--;
		um[v[left - 1]]--;

		if (um[v[right]] == 0) num++;
		um[v[right]]++;

		if (um[c] == 0) result = max(result, num + 1);
		else result = max(result, num);

		left++, right++;
		if (right == n) right = 0;
        if (result == k + 1) break;
	}
	cout << result;
	return 0;
}