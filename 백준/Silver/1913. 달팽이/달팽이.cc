#include <iostream>
#include <vector>

using namespace std;

int n, k, num = 2;
vector<vector<int>> v;

void drawSnail(const int& a, int& r, int& c);

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	v.assign(n, vector<int>(n, 0));
	v[n / 2][n / 2] = 1;

	pair<int, int> idx = { n / 2, n / 2 };
	for (int i = 3; i <= n; i += 2) 
	{
		drawSnail(i, idx.first, idx.second);
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cout << v[i][j] << ' ';
			if (v[i][j] == k) 
			{
				idx.first = i + 1;
				idx.second = j + 1;
			}
		}
		cout << '\n';
	}
	cout << idx.first << ' ' << idx.second;
	return 0;
}

void drawSnail(const int& a, int& r, int& c) 
{
	int dr[4] = { 0, 1, 0, -1 };
	int dc[4] = { 1, 0, -1, 0 };

	r -= 1, c -= 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < a - 1; j++)
		{
			r += dr[i], c += dc[i];
			v[r][c] = num++;
		}
	}
}