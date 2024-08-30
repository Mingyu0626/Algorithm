#include <iostream>>
#include <vector>
#include <algorithm>

using namespace std;

int n, result;
vector<int> v;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
    v.assign(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i; j++) result += v[j];	
    
	cout << result;
	return 0;
}