#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, temp, result;
priority_queue<int, vector<int>, greater<int>> pq;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> temp;
        pq.push(temp);
    }

    while (pq.size() > 1) 
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        result += a + b;
        pq.push(a + b);
    }

    cout << result;
    return 0;
}