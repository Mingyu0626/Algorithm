#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, k;
long long result;
vector<long long> v;
vector<long long> tree;

void recursion(int nodeNum, int l, int r);
void update(int nodeNum, int l, int r, int idx, long long newVal);
long long sum(int nodeNum, int l, int r, int start, int end);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	v.assign(n, 0);
	int treeHeight = (int)ceil(log2(n));
	tree.assign(pow(2, treeHeight + 1) + 2, 0);

	for (int i = 0; i < n; i++) cin >> v[i];

	recursion(1, 0, n - 1);

	long long a, b, c;
	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1) update(1, 1, n, b, c);
		else
		{
			result = sum(1, 1, n, b, c);
			cout << result << '\n';
		}
	}
    return 0;
}

void recursion(int nodeNum, int l, int r)
{
	if (l == r)
	{
		tree[nodeNum] = v[l];
		return;
	}
	int m = l + (r - l) / 2;
	recursion(nodeNum * 2, l, m);
	recursion(nodeNum * 2 + 1, m + 1, r);
	tree[nodeNum] = tree[nodeNum * 2] + tree[nodeNum * 2 + 1];
	return;
}

void update(int nodeNum, int l, int r, int idx, long long newVal)
{
	if (l == r)
	{
		tree[nodeNum] = newVal;
		return;
	}
	
	int m = l + (r - l) / 2;
	if (idx <= m) update(nodeNum * 2, l, m, idx, newVal);
	else update(nodeNum * 2 + 1, m + 1, r, idx, newVal);
	tree[nodeNum] = tree[nodeNum * 2] + tree[nodeNum * 2 + 1];
}

long long sum(int nodeNum, int l, int r, int start, int end)
{
	if (start > r || end < l) return 0;
	if (start <= l && r <= end) return tree[nodeNum];
	int m = l + (r - l) / 2;
	long long left = sum(nodeNum * 2, l, m, start, end);
	long long right = sum(nodeNum * 2 + 1, m + 1, r, start, end);
	return left + right;
}