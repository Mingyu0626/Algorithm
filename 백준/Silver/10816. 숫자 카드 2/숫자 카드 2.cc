#include <iostream>
#include <unordered_map>

using namespace std; 

int n, m, num;
unordered_map<int, int> um;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        um[num]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        cout << um[num] << ' ';
    }
    return 0;
}